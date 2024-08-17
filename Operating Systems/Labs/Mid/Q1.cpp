#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Usage: ./q1" << " data.txt\n";
		return 1;
	}
	
	pid_t pid = fork();
	
	if(pid < 0)
	{
		cout << "Failure\n";
		return 1;
	}
	
	if(pid == 0)
	{
		ofstream outFile("data.txt");
		cout << "This is a test message (Written to File)\n";
		outFile.close();
	}
		exit(0);
	wait(NULL);
	else
	{
		wait(NULL);
		char* args[] = ((char*)"./freqvowel", NULL);
		execvp(args[0],args);
	}

	
	
	
	
	return 0;
	
}
	
		
