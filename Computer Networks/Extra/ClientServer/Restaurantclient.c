#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void show_time_slots();

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Connected to server.\n");
    show_time_slots();

    while (1) {
        char message[1024];
        printf("Enter message (RESERVE <time_slot> or ADMIN): ");
        fgets(message, 1024, stdin);
        message[strcspn(message, "\n")] = 0;  // Remove trailing newline

        send(sock, message, strlen(message), 0);
        printf("Message sent: %s\n", message);

        if (strncmp(message, "RESERVE", 7) == 0) {
            valread = read(sock, buffer, 1024);
            buffer[valread] = '\0';
            printf("Server: %s\n", buffer);
        }
    }

    return 0;
}

void show_time_slots() {
    printf("Available Hi-Tea Slots:\n");
    printf("1. 15:00-16:00\n");
    printf("2. 16:00-17:00\n");
    printf("3. 17:00-18:00\n");
    printf("4. 18:00-19:00\n");

    printf("Available Dinner Slots:\n");
    printf("1. 19:00-20:00\n");
    printf("2. 20:00-21:00\n");
    printf("3. 21:00-22:00\n");
    printf("4. 22:00-23:00\n");
}
