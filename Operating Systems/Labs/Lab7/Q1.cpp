#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " filename\n";
        return 1;
    }

    const char *inFile = argv[1];
    const char *outFile = "output.txt";

    int inputFd = open(inFile, O_RDONLY);
    if (inputFd < 0) {
        cout << "Error opening input file";
        return 1;
    }
    if (dup2(inputFd, STDIN_FILENO) < 0) {
        cout << "Error duplicating input file descriptor to stdin";
        close(inputFd);
        return 1;
    }
    close(inputFd); 
    
    int outputFd = open(outFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outputFd < 0) {
        cout << "Error opening output file";
        return 1;
    }
    if (dup2(outputFd, STDOUT_FILENO) < 0) {
        cout << "Error duplicating output file descriptor for writing";
        close(outputFd);
        return 1;
    }
    close(outputFd); 

    const size_t bufferSize = 1024;
    char buffer[bufferSize];
    ssize_t bytesRead;

    while ((bytesRead = read(STDIN_FILENO, buffer, bufferSize)) > 0) {
        cout.write(buffer,bytesRead);
    }

    if (bytesRead < 0) 
    {
        cout << "Error reading from input file";
        return 1;
    }

    return 0;
}
