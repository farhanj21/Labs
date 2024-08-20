#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int num;
	int odd = 0;
	int even = 0;

	ifstream File;

	File.open("numbers.txt");
	ofstream OddFile("odd.txt");
	ofstream EvenFile("even.txt");

	if (!File)
	{
		cout << "File cannot be opened\n";
	}

	while (!File.eof())
	{
		File >> num;

		if (num % 2 == 0)
		{
			even = even + 1;
			EvenFile << num << "\n";
		}
		else
		{
			odd = odd + 1;
			OddFile << num << "\n";
		}
	}
	
	File.close();
	EvenFile.close();
	OddFile.close();

	cout << "The number of odd numbers are " << odd << "\n";
	cout << "The number of even numbers are " << even << "\n";

	system("pause");
	return 0;

}
