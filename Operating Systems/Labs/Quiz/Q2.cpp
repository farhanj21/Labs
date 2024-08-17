#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
        cout << "Usage: " << argv[0] << " Your Name\n";
        return 1;
    }
    
    char* name = argv[1];
    int size = 0;
    
    while (*name != '\0')
    {
    	size++;
    	name++;
    }
    	
    
    cout << "The length of your name is " << size << "\n";
    
    return 0;
}
