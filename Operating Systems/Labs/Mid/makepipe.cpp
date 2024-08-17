#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
using namespace std;

int main()
{
	pid_t Child_Pid1;
	pid_t Child_Pid2;
	
	const char* nameofPipe = "story_pipe";
	mkfifo(nameofPipe, 0666);
	
	Child_Pid1 = fork();
	
	if(Child_Pid1 == 0)
	{
		execlp("./sender", "./sender", NULL);
	}
	else
	{
		Child_Pid2 = fork();
		if (Child_Pid2 == 0)
		{
			execlp("./receiver", "./receiver", NULL);
		}
		else
		{
			wait(NULL);
			wait(NULL);
			
			unlink(nameofPipe);
		}
	}
	
	return 0;
}
