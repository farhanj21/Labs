#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	const char* nameofPipe = "story_pipe";
	ofstream openPipe(nameofPipe);
	
	const char* message = "A computer would deserve to be called intelligent if it could deceive a human into believing that it was human";
	
	openPipe << message;
	openPipe.close();
	
	return 0;
	
}
