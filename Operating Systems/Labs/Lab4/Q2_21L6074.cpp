#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() 
{
    int sizeArr;
    cout << "Enter the number of elements in the array: ";
    cin >> sizeArr;

    int array[sizeArr];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < sizeArr; i++) {
        cin >> array[i];
    }

    int fd1[2]; 
    int fd2[2]; 

    if (pipe(fd1) == -1 || pipe(fd2) == -1) 
	{
        perror("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) 
	{ 
        close(fd1[1]); 
        close(fd2[0]); 

        int receivedArr[sizeArr];

        read(fd1[0], receivedArr, sizeof(int) * sizeArr);

        int sum = 0;
        for (int i = 0; i < sizeArr; i++) {
            sum = sum +  receivedArr[i];
        }

        write(fd2[1], &sum, sizeof(int));

        close(fd1[0]);
        close(fd2[1]);

        exit(0);
    } 
	else
	 { 
        close(fd1[0]); 
        close(fd2[1]); 

        write(fd1[1], array, sizeof(int) * sizeArr);

        int sum;
        read(fd2[0], &sum, sizeof(int));

        cout << "Sum of the array: " << sum << "\n";

        close(fd1[1]);
        close(fd2[0]);
        wait(NULL); 
    }
    return 0;
}
