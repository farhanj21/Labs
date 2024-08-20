#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	int decision;
	char array[100];

	cout << "Enter 1 to Encrypt Data or Enter 2 to Decrypt Data\n";
	cin >> decision;
	
	if(decision == 1)
	{
		ifstream File;
     	ofstream File2;
	    File.open("input.txt");
	    File2.open("encrypt.txt");
	    
	    File.getline(array,100);
	    cout << array << "\n";
	    
	    for(int i = 0; i<100 && array[i] != '\0'; i++)
	    {
	    	array[i] = array[i] + 1;
		}
		
		cout << "Encrypted data is:\n" << array << "\n";
		File2 << array;
		File.close();
		File2.close();
	}
	
	else if (decision == 2)
	{
		ifstream File;
     	ofstream File2;
	    File.open("encrypt.txt");
	    File2.open("decrypt.txt");
	    
	    File.getline(array,100);
	    cout << array << "\n";
	    
	    for(int i = 0; i<100 && array[i] != '\0'; i++)
	    {
	    	array[i] = array[i] - 1;
		}
		
		cout << "Decrypted data is:\n" << array << "\n";
		File2 << array;
		File.close();
		File2.close();
	}
	
	else
	{
		cout << "Please enter only 1 or 2\n";
	}
	
	system("pause");
	return 0;
	
}
