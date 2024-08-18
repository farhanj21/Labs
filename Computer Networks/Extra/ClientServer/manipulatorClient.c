#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen("input.txt", "r");
    if (!input_file) {
        perror("Error opening input file");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input_file)) {
        send(client_socket, buffer, strlen(buffer), 0);
    }
    fclose(input_file);

    char recv_buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, recv_buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving data from server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    recv_buffer[bytes_received] = '\0';

    printf("Processed Text:\n%s\n", recv_buffer);

    close(client_socket);
    return 0;
}
