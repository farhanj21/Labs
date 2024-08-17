#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void displayArray(int array[], int size) 
{
    for (int i = 0; i < size; i++) 
	{
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[])
 {
    int numbers[10];

    for (int i = 1; i <= 10; i++) 
	{
        numbers[i - 1] = atoi(argv[i]);
    }

    pid_t child1PID = fork();
    pid_t child2PID = fork();

    if (child1PID == 0) {
        cout << "Child 1 (ID: " << getpid() << ", Parent ID: " << getppid() << ")" << "\n";
        cout << "Original Array in Child 1: ";
        displayArray(numbers, 10);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 - i; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }

        cout << "Sorted Array in Child 1: ";
        displayArray(numbers, 10);

        exit(0);
    }

    if (child2PID == 0) {
        cout << "Child 2 (ID: " << getpid() << ", Parent ID: " << getppid() << ")" << "\n";
        cout << "Original Array in Child 2: ";
        displayArray(numbers, 10);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 - i; j++) {
                if (numbers[j] < numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }

        cout << "Sorted Array in Child 2: ";
        displayArray(numbers, 10);

        exit(0);
    }

    cout << "Waiting for Child 1..." << "\n";
    wait(NULL);
    cout << "Waiting for Child 2..." << "\n";
    wait(NULL);

    cout << "Parent Process terminating (ID: " << getpid() << ", Parent's ID: " << getppid() << ")" << "\n";

	system("pause");
    return 0;
}

