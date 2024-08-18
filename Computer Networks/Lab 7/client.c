#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024
#define VOTES_FILE "Votes.txt"

int main() {
    int clientSocket;
    struct sockaddr_in serverAddress;
    char name[BUFFER_SIZE];
    char CNIC[BUFFER_SIZE];
    char vote[BUFFER_SIZE];

    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    write(clientSocket, name, strlen(name));

    printf("Enter your CNIC: ");
    fgets(CNIC, sizeof(CNIC), stdin);
    CNIC[strcspn(CNIC, "\n")] = 0;
    write(clientSocket, CNIC, strlen(CNIC));

    char listCandidate[BUFFER_SIZE];
    read(clientSocket, listCandidate, sizeof(listCandidate));
    printf("Candidates List:\n%s\n", listCandidate);

    printf("Enter symbol of the candidate you want to vote for: ");
    fgets(vote, sizeof(vote), stdin);
    vote[strcspn(vote, "\n")] = 0;
    write(clientSocket, vote, strlen(vote));

    printf("Vote casted successfully\n");

    FILE *votes_file = fopen(VOTES_FILE, "a");
    if (votes_file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(votes_file, "Name: %s\nCNIC: %s\nVote: %s\n\n", name, CNIC, vote);
    fclose(votes_file);

    close(clientSocket);

    return 0;
}

