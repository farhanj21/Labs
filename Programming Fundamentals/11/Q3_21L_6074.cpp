#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	
	char array[100];
	int buycode, buyquantity;
	int decision;
	float total, price[100];
	int code[100], quantity[100];
	char name[100];

    ifstream File;
	File.open("inventory.txt");
	
	if (!File)
	{
		cout << "File cannot be opened\n";
	}
	
	cout << "Code, Name, Quantity, Price\n";
	
	while (!File.eof())
	{
	    File.getline(array,100);
	    cout << array << "\n";
	}
	
	while (!File.eof())
	{
	    for (int i = 0; i < 10; i++)
	    {
	    	File >> code[i] << name[i] << quantity[i] << price[i];
		}
	}
	
	File.close();
	
	cout << "Enter code of item you want to buy\n";
	cin >> buycode;
	cout << "Enter quantity of item you want to buy\n";
	cin >> buyquantity;
	cout << "Do you want to buy more(1 to buy more, 0 to exit)\n";
	cin >> decision;
	
	if(decision == 1)
	{
	cout << "Enter code of item you want to buy\n";
	cin >> buycode;
	cout << "Enter quantity of item you want to buy\n";
	cin >> buyquantity;
	}
	
	else if(decision == 0)
	{
	  for (int i = 0; i < 10;i++)
	  {
	  	if(i == buycode)
	  	total = price[i] * buyquantity;
	  }
	  cout << "Your bill of item number " << buycode << " is " << total << "\n";
	}
	

	system("pause");
	return 0;
	
}
