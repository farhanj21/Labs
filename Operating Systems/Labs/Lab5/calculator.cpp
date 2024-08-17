#include <iostream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
#define PIPE_NAME_1 "./pipe1"
#define PIPE_NAME_2 "./pipe2"
#define MAX_ELEMENTS 100

int main() {
    vector<int> array(MAX_ELEMENTS);
    int sum = 0;
    int num_read;

    int fd1 = open(PIPE_NAME_1, O_RDONLY);
    num_read = read(fd1, &array[0], sizeof(int) * MAX_ELEMENTS);
    close(fd1);

    int num_elements = num_read / sizeof(int);
    for(int i = 0; i < num_elements; i++) {
        sum += array[i];
    }

    int fd2 = open(PIPE_NAME_2, O_WRONLY);
    write(fd2, &sum, sizeof(int));
    close(fd2);

    return 0;
}

