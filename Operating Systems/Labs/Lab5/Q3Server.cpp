#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

int main() {
    const char *pipeName = "NamedPipe";
    mkfifo(pipeName, 0666);  

    char buffer[50];
    int fd = open(pipeName, O_RDONLY);  

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(fd, buffer, sizeof(buffer));

        if (strlen(buffer) > 0) {
            char op;
            double operand1, operand2, result;
            sscanf(buffer, "%c %lf %lf", &op, &operand1, &operand2);

            switch (op) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0)
                        result = operand1 / operand2;
                    else
                        result = 0; 
                    break;
                default:
                    result = 0;
                    break;
            }

            cout << "Server: Received " << op << " " << operand1 << " " << operand2 << ", Result: " << result << "\n";
        }
        sleep(1);  
    }

    close(fd);
    unlink(pipeName);  
    return 0;
}

