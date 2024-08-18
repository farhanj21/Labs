#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char car_number[20];
    int start_time, end_time;
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    printf("Enter your car number: ");
    scanf("%s", car_number);
    printf("Enter start time (in 24-hour format): ");
    scanf("%d", &start_time);
    printf("Enter end time (in 24-hour format): ");
    scanf("%d", &end_time);

    // Send request to server
    sprintf(buffer, "%s %d %d", car_number, start_time, end_time);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, 1024);
    printf("%s\n", buffer);

    close(sock);
    return 0;
}
