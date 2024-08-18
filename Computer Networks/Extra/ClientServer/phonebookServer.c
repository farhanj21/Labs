#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket);
void search_phonebook(char *name, int client_socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accept and handle incoming connections
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) >= 0) {
        printf("New connection accepted\n");

        if (pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket) != 0) {
            perror("Could not create thread");
            close(new_socket);
        }
    }

    if (new_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *handle_client(void *client_socket) {
    int socket = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int valread;

    while ((valread = read(socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[valread] = '\0';
        if (strcmp(buffer, "Exit") == 0) {
            printf("Client requested to exit\n");
            break;
        }
        search_phonebook(buffer, socket);
    }

    close(socket);
    pthread_exit(NULL);
}

void search_phonebook(char *name, int client_socket) {
    FILE *file = fopen("phonebook.txt", "r");
    char line[256];
    char response[BUFFER_SIZE] = "No contact found.\n";
    int found = 0;

    if (file == NULL) {
        perror("Could not open phonebook.txt");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name) != NULL) {
            if (found == 0) {
                strcpy(response, line);
            } else {
                strcat(response, line);
            }
            found = 1;
        }
    }

    fclose(file);

    // Send the response to the client
    send(client_socket, response, strlen(response), 0);
}
