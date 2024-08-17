#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]) 
{
    cout << "Process ID of Main.cpp is " << getpid() << "\n";

    if (execlp("./q1info", "q1info",nullptr) == -1) 
    {
        perror("Failed");
        return 1;
    }
	system("pause");
    return 0;
}

	

