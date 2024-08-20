//Assignment 4 by Syed Farhan Jafri(21L-6074) Section: BSE-1A

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void ImperfectPalindrome(char words[20]);
void SuperAnagram(char FirstWord[20], char SecondWord[20]);

int main()
{
	char FirstWord[20];
	char SecondWord[20];
	ifstream File;

	File.open("assignment 4 file.txt");                              //opening file             
	
	if (!File)
	{
		cout << "File cannot be opened\n";
	}                       
	
	cout << "1stWord Imperfect Palindrome?    2ndWord Imperfect Palindrome?    Are They Super-Anagrams?\n\n";

	while (!File.eof())                                  //reading from file
	{
		File >> FirstWord >> SecondWord;
		cout << FirstWord << " " << SecondWord << "\n";
		ImperfectPalindrome(FirstWord);                       //calling of functions
		ImperfectPalindrome(SecondWord);
		SuperAnagram(FirstWord, SecondWord);
		cout << "\n";
	}

	File.close();                              //closing file

	system("pause");
	return 0;
}

void ImperfectPalindrome(char words[20])           //function to check for imperfect palindrome
{
	int c = 0;
	int size = strlen(words);

	for (int i = 0; words[i] != '\0'; i++)                   //running loop until there is a void character
	{
		if (words[i] != words[size - i - 1])                 //comparing characters from first letter with last letter of word
			c = c + 1;
	}

	if (c < 3 && c > 0)                                    
		cout << "yes ";
	else
		cout << "no ";
}

void SuperAnagram(char FirstWord[20], char SecondWord[20])        //function to check for super-anagram
{
	int sizeFirstWord = strlen(FirstWord);
	int sizeSecondWord = strlen(SecondWord);
	bool check = true;

	for (int i = 0;i < sizeFirstWord;i++)      // finding super-anagram
	{
		for (int j = 0;j < sizeSecondWord;j++)
		{
			if (FirstWord[i] == SecondWord[j])         //comparing letters of both words
				SecondWord[j] = '\0';
		}
		
		for (int c = i + 1;c < sizeFirstWord;c++)
		{
			if (FirstWord[i] == FirstWord[c])                   
				FirstWord[c] = '\0';
		}
		FirstWord[i] = '\0';
	}

	for (int k = 0;k < sizeFirstWord;k++)
	{
		if (SecondWord[k] == '\0' && FirstWord[k] == '\0')            
			check = true;
		else
			check = false;
			break;
	}

	if (check == true)
		cout << "yes" << " \n";
	else
		cout << "no" << " \n";

}
