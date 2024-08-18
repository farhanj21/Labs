#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_SLOTS 10
#define SLOT_COST_PER_HOUR 10

typedef struct {
    char car_number[20];
    int start_time;
    int end_time;
} ParkingSlot;

ParkingSlot parking_database[MAX_SLOTS];
int num_slots_filled = 0;
pthread_mutex_t database_mutex = PTHREAD_MUTEX_INITIALIZER;

void display_database() {
    printf("Parking Database:\n");
    printf("Car Number\tStart Time\tEnd Time\tFare\n");
    for (int i = 0; i < num_slots_filled; i++) {
        printf("%s\t\t%d\t\t%d\t\tRs. %d\n", parking_database[i].car_number,
               parking_database[i].start_time, parking_database[i].end_time,
               (parking_database[i].end_time - parking_database[i].start_time) * SLOT_COST_PER_HOUR);
    }
}

int is_allowed(char *car_number) {
    // Load allowed vehicle numbers from file
    FILE *file = fopen("Vehicle_Numbers_List.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char buffer[20];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        if (strcmp(car_number, buffer) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[1024] = {0};
    char car_number[20];
    int start_time, end_time;

    // Receive client's request
    read(client_socket, buffer, sizeof(buffer));
    sscanf(buffer, "%s %d %d", car_number, &start_time, &end_time);

    // Check if the car number is allowed
    if (!is_allowed(car_number)) {
        write(client_socket, "Car number not allowed for parking.\n", strlen("Car number not allowed for parking.\n"));
        close(client_socket);
        pthread_exit(NULL);
    }

    // Acquire lock to access shared database
    pthread_mutex_lock(&database_mutex);

    // Check if parking slot is available
    if (num_slots_filled < MAX_SLOTS) {
        strcpy(parking_database[num_slots_filled].car_number, car_number);
        parking_database[num_slots_filled].start_time = start_time;
        parking_database[num_slots_filled].end_time = end_time;
        num_slots_filled++;
        write(client_socket, "Parking slot booked successfully.\n", strlen("Parking slot booked successfully.\n"));
    } else {
        write(client_socket, "No slot is available at this time.\n", strlen("No slot is available at this time.\n"));
    }

    // Release lock
    pthread_mutex_unlock(&database_mutex);

    // Display database
    display_database();

    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_fd, client_socket, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept and handle client connections
    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
        pthread_detach(thread_id); // Detach the thread
    }

    return 0;
}
