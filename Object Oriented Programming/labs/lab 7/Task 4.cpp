#include <cstring>
#include <iostream>
using namespace std;

class CompareString 
{
 
public:
    char* str;
	int size;

    CompareString(char str1[])
    {
        size = strlen(str1);
		str =  new char[size];
		for (int i = 0; i < size; i++)
		{
			str[i] = str1[i];
		}
    }

    int operator==(CompareString s2)
    {
        if (size == s2.size)
		{
			for(int i = 0; i < size; i++)
			{
				if (str[i] != s2.str[i])
				{
					return 0;
				}
			}
			return 1;
		}
		return 0;
  
    }
 
    int operator<=(CompareString s3)
    {
        if (strlen(str) <= strlen(s3.str))
            return 1;
        else
            return 0;
    }

    int operator>=(CompareString s3)
    {
        if (strlen(str) >= strlen(s3.str))
            return 1;
        else
            return 0;
    }
};
 
void compare(CompareString s1, CompareString s2)
{
    if (s1 == s2)
        cout << s1.str << " is equal to " << s2.str << "\n";
    else 
	{
        cout << s1.str << " is not equal to " << s2.str << "\n";;
        if (s1 >= s2)
            cout << s1.str << " is greater than " << s2.str << "\n";
        else
            cout << s2.str << " is greater than " << s1.str << "\n";
    }
}
 

int main()
{
  char s1[50], s2[50];
  cout << "Enter string 1 and string 2\n";
  cin.getline(s1,50);
  cin.getline(s2,50);
  
  CompareString str1(s1);
  CompareString str2(s2);
 
    compare(s1, s2);
 
	system("pause");
    return 0;
}
 

