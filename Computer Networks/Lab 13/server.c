#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int evaluateExpression(char *expression, int *result) {
    char operator;
    int num;
    if (sscanf(expression, "%c %d", &operator, &num) != 2) {
        return -1; 
    }
    if (operator == '+') {
        *result += num;
    } else if (operator == '-') {
        *result -= num;
    } else {
        return -1;
    }
    return 0; 
}

int main() {
    int serverSocket, clientSocket, valread;
    struct sockaddr_in serverAddr;
    int opt = 1;
    int addrLen = sizeof(serverAddr);
    char buffer[BUFFER_SIZE] = {0};
    int result = 0;

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server Running\n");

    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&serverAddr, (socklen_t *)&addrLen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    char welcomeMsg[BUFFER_SIZE];
    snprintf(welcomeMsg, sizeof(welcomeMsg), "Current result: %d\n", result);
    send(clientSocket, welcomeMsg, strlen(welcomeMsg), 0);

    while (1) {
        valread = read(clientSocket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        if (evaluateExpression(buffer, &result) == -1) {
            char errorMsg[] = "Send expressions in the format: '+/- number'\n";
            send(clientSocket, errorMsg, strlen(errorMsg), 0);
        } else {
            printf("Received expression: %s\n", buffer);
            printf("Updated result: %d\n", result);
            char response[BUFFER_SIZE];
            snprintf(response, sizeof(response), "Received: %s. Updated result: %d\n", buffer, result);
            send(clientSocket, response, strlen(response), 0);
        }

        memset(buffer, 0, BUFFER_SIZE); // Clear buffer
    }

    close(serverSocket);
    return 0;
}

