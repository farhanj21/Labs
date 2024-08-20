#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void lookUpName(char names[][100], int numbers[100]);

int main()
{
	char names[100][100];
	int numbers[100];
	
	ifstream File;
	File.open("PhoneBook.txt");
	
	if (!File)
	{
		cout << "File cannot be opened\n";
	}
	
	while (!File.eof())
	{
		for (int i = 0; i<5; i++)
		{
			File >> names[i] >> numbers[i];
		}
	}
	
	File.close();
	
	lookUpName(names, numbers);
	
	system("pause");
	return 0;
}

void lookUpName(char names[][100], int numbers[100])
{

	char find[100];
	int c = 0;
	bool flag = false;
	cout << "Enter the name whose number you want to look for\n";
	cin >> find;
	int size = strlen(find);
	
	for(int i = 0; i<5; i++)
	{
		c = 0;
		for (int j = 0; find[j] != '\0';j++)
		{
			if(find[j] == names[i][j])
		    {
		    	c = c + 1;
		    	if (c == size)
		    	{
		    	    cout << find << "'s number is " << numbers[i]<< "\n";
		    	    flag = true;
				}
		    }
		}
	}
	
	if (flag==false)
	{
		cout << find << "'s number is not in the file\n";
	}
	
}
