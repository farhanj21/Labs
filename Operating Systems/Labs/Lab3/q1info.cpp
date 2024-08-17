#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]) 
{
    cout << "Process ID of Main.cpp is " << getpid() << "\n";
    cout << "Name: Farhan\n RollNum: 21L-6074\n Semester:5\n";
    
    system("pause");
    return 0;
}
