#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;
int main()
{
	const char* nameofPipe = "story_pipe";
	ifstream openPipe(nameofPipe);
	
	string msg;
	
	getline(openPipe, msg);
	
	map<string, int> stopWords = {{"a",0}, {"to",0}, {"be",0}, {"it",0}, {"for",0}, {"of",0}, {"the",0}};
	
	istringstream ss(msg);
	cout << msg << "\n";
	string word;
	
	while(ss >> word)
	{
		if(stopWords.find(word) != stopWords.end())
		{
			stopWords[word]++;
		}
	}
	
	for(auto& pair: stopWords)
	{
		cout << pair.first << ":" << pair.second << "\n";
	}
	
	return 0;
	
}
