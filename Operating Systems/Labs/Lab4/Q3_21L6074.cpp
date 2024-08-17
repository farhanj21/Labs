#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
using namespace std;


int main(int argc, char *argv[]) 
{
    if (argc != 3) 
	{
        cout << "Usage: " << argv[0] << " <sourcefile> <destinationfile>\n";
        return 1;
    }

    char *sourceF = argv[1];
    char *destinationF = argv[2];

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) { 
        close(pipe_fd[1]); 

        ofstream dest(destinationF, ios::out | ios::binary);
        if (!dest.is_open()) {
            perror("Failed to open destination file");
            close(pipe_fd[0]);
            return 1;
        }

        int size;
        if (read(pipe_fd[0], &size, sizeof(int)) == -1) {
            perror("Read size from pipe failed");
            close(pipe_fd[0]);
            dest.close();
            return 1;
        }

        cout << "Child process (PID " << getpid() << ") received content size: " << size << "\n";

        char buffer[BUFFER_SIZE];
        int bytesSize;
        while ((bytesSize = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
            dest.write(buffer, bytesSize);
        }

        close(pipe_fd[0]);
        dest.close();
        return 0;
    } else { 
        close(pipe_fd[0]); 

        ifstream source(sourceF, ios::in | ios::binary);
        if (!source.is_open()) {
            perror("Failed to open source file");
            close(pipe_fd[1]);
            return 1;
        }

        source.seekg(0, ios::end);
        int file_size = source.tellg();
        source.seekg(0, ios::beg);

        cout << "Parent process (PID " << getpid() << ") sending content size: " << file_size << "\n";

        if (write(pipe_fd[1], &file_size, sizeof(int)) == -1) {
            perror("Write size to pipe failed");
            close(pipe_fd[1]);
            source.close();
            return 1;
        }

        char buffer[BUFFER_SIZE];
        int bytesSize;
        while ((bytesSize = source.readsome(buffer, sizeof(buffer))) > 0) {
            if (write(pipe_fd[1], buffer, bytesSize) == -1) {
                perror("Write to pipe failed");
                close(pipe_fd[1]);
                source.close();
                return 1;
            }
        }

        close(pipe_fd[1]);
        source.close();

        wait(NULL);
        return 0;
    }
}
