#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
	fstream inFile("data.txt");
	map<char, int> vowels = {{'a',0}, {'e',0}, {'i',0}, {'o',0}, {'u',0}};
	
	if(inFile.is_open())
	{
		char character;
		
		while(inFile>>character)
		{
			character = tolower(character);
			if(vowels.find(character) != vowels.end())
			{
				vowels[character++];
			}
		}
	}
		
		inFile.close();
		
		cout << "Frequency of each vowel: ";
		for(const auto &pair: vowels)
		{
			cout << pair.first << ":" << pair.second << "\n";
		}
		
	
	return 0;
}
		
		 
