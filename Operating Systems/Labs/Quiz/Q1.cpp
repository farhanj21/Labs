#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char* argv[])
{
	int array[5][5] = {(500, 200, 12, 13, 15), (140, 15, 160, 170, 20), (20, 40, 700,1000,11), (10, 20, 20, 20, 20), (20, 10, 12, 10, 1000)};
				
	
	pid_t child1 = fork();
	
	if(child1 == 0)
	{
		
		int totalSum = 0, uSum =0, dSum=0;
		
		for(int i=0; i<5;i++)
		{
			for(int j=0; j<5; j++)
			{
				totalSum = totalSum + array[i][j];
			}
		}
		cout << "Total Sum is " << totalSum;
			
		for(int i=0; i<5;i++)
		{
			for(int j=0; j<5; j++)
			{
				uSum = uSum + array[i][j];
			}
		}
		return uSum;
	}
	else
	{
		pid_t child2 = fork();
		
		if(child2 = 0);
	}
	
	
	}
	
				
					
			
