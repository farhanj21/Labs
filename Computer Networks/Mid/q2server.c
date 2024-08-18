#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024


//I wrote this code for API connection but did not connect one due to lack of time

void *handle_client(void *arg) {
    int clientSocket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    WeatherData WeatherInfo;

    recv(clientSocket, buffer, BUFFER_SIZE, 0);

    if (get_WeatherInfo(buffer, &WeatherInfo) == 0) {

        send(clientSocket, &WeatherInfo, sizeof(WeatherData), 0);
    } else {
 
        strncpy(buffer, "Invalid Location", BUFFER_SIZE);
        send(clientSocket, buffer, strlen(buffer), 0);
    }

    close(clientSocket);

    return NULL;
}

int main() {
    int serverSocket;
    int clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressSize;
    pthread_t thread_id;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Binding Error");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 5) == -1) {
        perror("Listening Error");
        exit(EXIT_FAILURE);
    }

    printf("Server has started on %d\n", PORT);

    while (1) {
        clientAddressSize = sizeof(clientAddress);
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);
        if (clientSocket == -1) {
            perror("Accepting Error");
            continue;
        }

        pthread_create(&thread_id, NULL, handle_client, (void *)&clientSocket);
        pthread_detach(thread_id);
    }

    close(serverSocket);

    return 0;
}
