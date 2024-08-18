#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 8080
#define maxClients 5
#define BUFFER_SIZE 1024

void voterAuthentication(int clientSocket) {
    char name[BUFFER_SIZE];
    char CNIC[BUFFER_SIZE];
    char buff[BUFFER_SIZE];

    read(clientSocket, name, sizeof(name));
    read(clientSocket, CNIC, sizeof(CNIC));

    FILE *file = fopen("Voters_List.txt", "r");

    int flag = 0;
    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (strstr(buff, name) != NULL && strstr(buff, CNIC) != NULL) {
            flag = 1;
            break;
        }
    }

    fclose(file);

    if (flag) {
        char welcomeMSG[] = "The candidates are:\n";
        write(clientSocket, welcomeMSG, strlen(welcomeMSG));
    } else {
        char errorMSG[] = "Authentication failed. Please try again.\n";
        write(clientSocket, errorMSG, strlen(errorMSG));
        close(clientSocket);
        return;
    }
}

void send_candidates_list(int clientSocket) {
    FILE *file = fopen("Candidates_List.txt", "r");

    char buff[BUFFER_SIZE];
    char listCandidate[BUFFER_SIZE] = "";

    while (fgets(buff, sizeof(buff), file) != NULL) {
        strcat(listCandidate, buff);
    }

    fclose(file);

    write(clientSocket, listCandidate, strlen(listCandidate));
}

void *handle_client(void *arg) {
    int clientSocket = *((int *)arg);
    
    voterAuthentication(clientSocket);
    send_candidates_list(clientSocket);

    char vote[BUFFER_SIZE];
    read(clientSocket, vote, sizeof(vote));
    printf("Received vote: %s\n", vote);

    close(clientSocket);
    pthread_exit(NULL);
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int addressLength = sizeof(clientAddress);
    int opt = 1;

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, maxClients) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&addressLength)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected\n");

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)&clientSocket) != 0) {
            perror("Thread creation failed");
            close(clientSocket);
        }
    }

    return 0;
}

