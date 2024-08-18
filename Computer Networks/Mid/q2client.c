#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024

//I wrote this code for API connection but did not connect one due to lack of time

int main() {
    int clientSocket;
    struct sockaddr_in serverAddress;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family =AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Failed to Connect to Server");
        exit(EXIT_FAILURE);
    }

    char location[BUFFER_SIZE];
    printf("Enter location (name or coordinates): ");
    scanf("%s", location);

    send(clientSocket, location, strlen(location), 0);
    WeatherData WeatherInfo;
    recv(clientSocket, &WeatherInfo, sizeof(WeatherData), 0);


    printf("\nWeather forecast for %s:\n", location);
    printf("Temperature: %.2f°C\n", WeatherInfo.temperature);
    printf("Humidity: %.2f%%\n", WeatherInfo.humidity);
    printf("Pressure: %.2f hPa\n", WeatherInfo.pressure);

    close(clientSocket);

    return 0;
}
