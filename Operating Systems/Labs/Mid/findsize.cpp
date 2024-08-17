#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
	fstream inFile("data.txt");
	
	int size = 0;
	string msg;
	getline(inFile, msg);
	inFile.close();
	
	cout << "Size of message is " << msg.size() << "\n";
	
	
	
	return 0;
	
}
