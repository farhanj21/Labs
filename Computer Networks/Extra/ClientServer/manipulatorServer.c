#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("Error reading from client");
        close(client_socket);
        return NULL;
    }
    buffer[bytes_read] = '\0';

    FILE *output_file = fopen("output.txt", "a");
    if (!output_file) {
        perror("Error opening output file");
        close(client_socket);
        return NULL;
    }

    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        for (int i = 0; line[i]; i++) {
            if (isupper(line[i]))
                line[i] = tolower(line[i]);
            else if (islower(line[i]))
                line[i] = toupper(line[i]);
        }
        fprintf(output_file, "%s - PROCESSED BY SERVER\n", line);
        line = strtok(NULL, "\n");
    }
    fclose(output_file);
    close(client_socket);

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) == -1) {
        perror("Error listening on socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        int *pclient = malloc(sizeof(int));
        *pclient = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, pclient);
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}
