#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;


int main(int argc, char *argv[]) 
{
    vector<int> num;

    for (int i = 1; i <= 10; i++) {
        num.push_back(atoi(argv[i]));
    }

    pid_t childPID = fork();

    if (childPID == 0) 
    { 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 - i; j++) {
                if (num[j] > num[j + 1]) 
                {
                    swap(num[j], num[j + 1]);
                }
            }
        }

        cout << "Sorted Array Child Process ID = " << getpid() << "\n";
        for (int i = 0; i < 10; i++) 
        {
            cout << num[i] << " ";
        }
        cout << "\n";


        exit(0);
    } 
	
	else 
    { 
        wait(NULL);        
        cout << "Parent process (ID " << getpid() << ") exiting." << "\n";
    }
	
	system("pause");
	return 0;
}

