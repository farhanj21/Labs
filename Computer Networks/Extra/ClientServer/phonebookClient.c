#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void query_server(int socket);

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    query_server(sock);

    close(sock);
    return 0;
}

void query_server(int socket) {
    char name[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *output_file = fopen("client_output.txt", "a");

    if (output_file == NULL) {
        perror("Could not open client_output.txt");
        return;
    }

    while (1) {
        printf("Enter the name to search (or 'Exit' to quit): ");
        fgets(name, BUFFER_SIZE, stdin);
        name[strcspn(name, "\n")] = 0;

        send(socket, name, strlen(name), 0);
        if (strcmp(name, "Exit") == 0) {
            break;
        }

        int valread = read(socket, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';

        printf("Server response:\n%s\n", buffer);
        fprintf(output_file, "Query: %s\nResponse:\n%s\n", name, buffer);
    }

    fclose(output_file);
}
