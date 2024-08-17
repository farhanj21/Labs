#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/wait.h>
using namespace std;

int main() {
    int pipefd[2];
    pid_t pid;    

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        close(pipefd[1]);

        string msg;
        char buffer;

        while (read(pipefd[0], &buffer, 1) > 0)
        {
            if (islower(buffer))
                buffer = toupper(buffer);
            else if (isupper(buffer))
                buffer = tolower(buffer);
           
            msg = msg + buffer;
        }

        close(pipefd[0]);

        cout << "Child Process ID: " << getpid() << "\n";
        cout << "Modified String: " << msg << "\n";
    }
    else
    {
        close(pipefd[0]);

        string msg = "Winter is Coming";
 
        write(pipefd[1], msg.c_str(), msg.length());
        close(pipefd[1]);

        wait(NULL);

        cout << "Parent Process ID: " << getpid() << "\n";
        cout << "Original String: " << msg << "\n";
    }
       return 0;
}
