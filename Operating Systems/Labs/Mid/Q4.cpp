#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
using namespace std;

struct Person
{
	const char* name;
	int time;
};

Person people[] = { {"Hamza", 1}, {"Ali", 3}, {"Alan", 1}, {"Newton", 8}, {"John", 12}};

bool crossing(int &remainingTime, const Person &p1, const Person &p2 = {"",0})
{

	if (remainingTime >= time)
	{
		remainingTime = remainingTime - time;
		
		if(p2.name[0] != '\0')
		{
			cout << p1.name[0] << " and " << p2.name[0] << " cross the river. Remaining Time is " << remainingTime << "\n";
		}
		else
		{
			cout << p1.name[0] << " is crossing river. Remaining Time is " << remainingTime  << "\n";
			}
			return true;
			}
			
			return false;
}

bool returning(int &remainingTime, const Person &p)
{
	if (remainingTime >= p.time)
	{
		cout << p.name << " is returning. Remaining Time is " << remainingTime << "\n";
		return true;
	}
	return false;
}

void childProcess(int pipefd[])
{
	close (pipefd[0]);
	
	int remainingTime = 30;
	
	crossing(remainingTime, people[1], people[0]);
	returning(remainingTime, people[1]);
	
	crossing(remainingTime, people[4], people[2]);
	returning(remainingTime, people[1]);
		
	write(pipefd[1], &remainingTime, sizeof(int));
	close(pipefd[1]);
}

int main()
{
	int pipefd[2];
	
	pid_t pid = fork();
	
	if(pid == 0)
	{
		childProcess(pipefd);
	}
	else
	{
		close(pipefd[1]);
		int remainingTime;
		wait(NULL);
		read(pipefd[0], &remainingTime, sizeof(int));
		close(pipefd[0]);
		
		if(remainingTime >=0)
		{
			cout << "Family crossed with child process\n";
		}
		else
		{
			cout << "Error\n";
		}
	}
	
	return 0;
	
}
