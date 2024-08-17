#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

#define PIPE_NAME_1 "./pipe1"
#define PIPE_NAME_2 "./pipe2"
#define MAX_BUF 1024

void change_case(std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char buf[MAX_BUF];
    int fd1, fd2;

    fd1 = open(PIPE_NAME_1, O_RDONLY);
    read(fd1, buf, MAX_BUF);
    close(fd1);

    string message(buf);

    change_case(message);

    fd2 = open(PIPE_NAME_2, O_WRONLY);
    write(fd2, message.c_str(), message.length());
    close(fd2);

    return 0;
}

