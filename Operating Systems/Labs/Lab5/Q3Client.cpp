#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

int main() {
    const char *pipeName = "NamedPipe";
    int fd = open(pipeName, O_WRONLY);  

    if (fd == -1) {
        perror("Error opening the named pipe");
        return 1;
    }

    char input[50];
    cout << "Client: Enter operator and two operands (e.g., + 4 10): ";
    cin.getline(input, sizeof(input));

    write(fd, input, strlen(input));

    char result[50];
    read(fd, result, sizeof(result));
    cout << "Client: Received result from server: " << result << "\n";

    close(fd);
    return 0;
}

