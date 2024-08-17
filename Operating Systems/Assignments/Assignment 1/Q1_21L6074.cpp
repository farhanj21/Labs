#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
    string command;
   
    while (true)
    {
        cout << "Enter a command (cp, mkdir, ls, or exit): ";
        getline(cin, command);

        vector<string> tokens;
        char* token = strtok(const_cast<char*>(command.c_str()), " ");
        while (token != nullptr) 
		{
            tokens.push_back(token);
            token = strtok(nullptr, " ");
        }

        if (tokens.size() == 1 && tokens[0] == "exit")
        {
            cout << "Exiting the shell\n";
            break;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            cout << "Error creating child process\n";
            return 1;
        }
        else if (pid == 0)
        {
            char* args[tokens.size() + 1];
            for (size_t i = 0; i < tokens.size(); ++i)
            {
                args[i] = const_cast<char*>(tokens[i].c_str());
            }
            args[tokens.size()] = nullptr;

            execvp(args[0], args);
           
            cout << "Incorrect Command\n";
            exit(1);
        }
        else
        {
            int condi;
            waitpid(pid, &condi, 0);
        }
    }

system("pause");
    return 0;
}

