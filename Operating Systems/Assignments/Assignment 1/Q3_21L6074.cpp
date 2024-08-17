#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() 
{
    int totalProcesses;
    
    cout << "Enter a number between 1 and 10: ";
    cin >> totalProcesses;

    if (totalProcesses < 1 || totalProcesses > 10) 
	{
        cout << "Invalid input. Please enter a number between 1 and 10\n" ;
        return 1;
    }

    for (int i = 0; i < totalProcesses; ++i) 
	{
        pid_t childPID = fork();

        if (childPID < 0) 
		{
            cout << "Fork failed\n";
            return 1;
        } 
		else if (childPID == 0) 
		{
            cout << "Child PID: " << getpid() << ", Parent PID: " << getppid() << "\n";
            break; 
            
        } 
		else
        {
            
            wait(NULL); 
        }
    }

	system("pause")
    return 0;
}
