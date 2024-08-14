#include <iostream>
#include <string>
using namespace std;

int stringCompare(char const* string1, char const* string2)
{
	char s1 = *string1, s2 = *string2;
	
	if(s1>s2)
	{
		return 1;
	}
	if(s1<s2)
	{
		return -1;
	}
	if(s1=='\0')
	{
		return 0;
	}
	return stringCompare(string1+1,string2+1);
	
}

int main()
{
	char s1[100];
	char s2[100];
	
	cout <<"Enter strings\n";
	cin.getline(s1,100);
	cin.getline(s2,100);
	
	int eq = stringCompare(s1,s2);
	if(eq==0)
	{
		cout << "Strings are equal\n";
	}
	else
	{
		cout << "Strings are not equal\n";
	}
	
	system("pause");
	return 0;
}
