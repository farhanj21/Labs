#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PIPE_NAME_1 "./pipe1"
#define PIPE_NAME_2 "./pipe2"
#define MAX_BUF 1024

int main() {
    char buf[MAX_BUF];
    int fd1, fd2;

    if (mkfifo(PIPE_NAME_1, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    if (mkfifo(PIPE_NAME_2, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    cout << "Enter a message: ";
    cin.getline(buf, MAX_BUF);

    fd1 = open(PIPE_NAME_1, O_WRONLY);
    write(fd1, buf, strlen(buf));
    close(fd1);

    fd2 = open(PIPE_NAME_2, O_RDONLY);
    read(fd2, buf, MAX_BUF);
    std::cout << "Received: " << buf << "\n";
    close(fd2);

    unlink(PIPE_NAME_1);
    unlink(PIPE_NAME_2);

    return 0;
}

