#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define QUEUE_SIZE 10
#define SLOT_COUNT 4
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "HotelManager"
#define FILENAME "reservations.txt"

typedef struct {
    int socket;
    struct sockaddr_in address;
    socklen_t addr_len;
    char name[30];
    time_t join_time;
} Client;

Client *clients[MAX_CLIENTS];
Client *waiting_queue[QUEUE_SIZE];
int queue_front = 0;
int queue_rear = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

char *time_slots_hi_tea[SLOT_COUNT] = {"15:00-16:00", "16:00-17:00", "17:00-18:00", "18:00-19:00"};
char *time_slots_dinner[SLOT_COUNT] = {"19:00-20:00", "20:00-21:00", "21:00-22:00", "22:00-23:00"};

void *handle_client(void *arg);
void add_client_to_queue(Client *client);
void remove_client_from_queue();
void show_admin_page();
void write_reservation_to_file(char *reservation);

void sigint_handler(int sig) {
    printf("Shutting down the server...\n");
    exit(0);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addr_len = sizeof(address);

    signal(SIGINT, sigint_handler);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_t thread;
        Client *client = (Client *)malloc(sizeof(Client));
        client->socket = new_socket;
        client->address = address;
        client->addr_len = addr_len;
        client->join_time = time(NULL);
        pthread_create(&thread, NULL, handle_client, (void *)client);
        pthread_detach(thread);
    }

    return 0;
}

void *handle_client(void *arg) {
    Client *client = (Client *)arg;
    char buffer[1024];
    int valread;

    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = client;
            printf("Client connected: %s\n", inet_ntoa(client->address.sin_addr));
            break;
        }
        if (i == MAX_CLIENTS - 1) {
            printf("Client queue full, adding to waiting queue.\n");
            add_client_to_queue(client);
            pthread_mutex_unlock(&clients_mutex);
            return NULL;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    while ((valread = read(client->socket, buffer, 1024)) > 0) {
        buffer[valread] = '\0';
        if (strncmp(buffer, "RESERVE", 7) == 0) {
            char reservation[128];
            sprintf(reservation, "Client %s reserved %s", client->name, buffer + 8);
            write_reservation_to_file(reservation);
        } else if (strncmp(buffer, "ADMIN", 5) == 0) {
            show_admin_page();
        }
        memset(buffer, 0, sizeof(buffer));
    }

    close(client->socket);
    free(client);
    return NULL;
}

void add_client_to_queue(Client *client) {
    pthread_mutex_lock(&queue_mutex);
    if ((queue_rear + 1) % QUEUE_SIZE == queue_front) {
        printf("Waiting queue is full, rejecting client: %s\n", inet_ntoa(client->address.sin_addr));
        close(client->socket);
        free(client);
    } else {
        waiting_queue[queue_rear] = client;
        queue_rear = (queue_rear + 1) % QUEUE_SIZE;
        printf("Client added to waiting queue: %s\n", inet_ntoa(client->address.sin_addr));
    }
    pthread_mutex_unlock(&queue_mutex);
}

void remove_client_from_queue() {
    pthread_mutex_lock(&queue_mutex);
    if (queue_front != queue_rear) {
        Client *client = waiting_queue[queue_front];
        queue_front = (queue_front + 1) % QUEUE_SIZE;
        pthread_mutex_unlock(&queue_mutex);

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = client;
                printf("Client moved from queue to active: %s\n", inet_ntoa(client->address.sin_addr));
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    } else {
        pthread_mutex_unlock(&queue_mutex);
    }
}

void show_admin_page() {
    char username[50], password[50];
    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(username, ADMIN_USERNAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
        FILE *file = fopen(FILENAME, "r");
        if (file == NULL) {
            perror("Could not open reservations file");
            return;
        }

        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }

        fclose(file);
    } else {
        printf("Invalid admin credentials.\n");
    }
}

void write_reservation_to_file(char *reservation) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Could not open reservations file");
        return;
    }

    fprintf(file, "%s\n", reservation);
    fclose(file);
}
