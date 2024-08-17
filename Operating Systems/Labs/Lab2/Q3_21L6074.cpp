#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
 {
    if (argc != 2) 
	{
        cout << "Usage: " << argv[0] << " Number of processes = 1-10\n";
        return 1;
    }

    int numOfProcesses = atoi(argv[1]);

    if (numOfProcesses < 1 || numOfProcesses > 10) 
	{
        cout << "Number of processes should be between 1 and 10.\n";
        return 1;
    }

    for (int i = 1; i <= numOfProcesses; i++) {
        pid_t childPID = fork();

        if (childPID < 0) {
            cout << "Error creating child process " << i << "\n";
            return 1;
        } 
		else if (childPID == 0) 
		{
            cout << "Child " << i << " (ID: " << getpid() << ", Parent ID: " << getppid() << ")\n";
            exit(0);
        } 
		else 
		{
            wait(NULL);
            if (i < numOfProcesses) 
			{
                cout << "Parent " << i << " (ID: " << getpid() << ", Parent ID: " << getppid() << ")\n";
            }
        }
    }

	system("pause")
    return 0;
}

