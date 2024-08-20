#include <iostream>
using namespace std;
void PrimeFrequency(int c, int search);

int main()
{
	int startindex, endindex, search, c;
	int arr[100] = {};
	int num = 0, size = 0;
	bool found;

	cout << "Enter values into Array(-1 to exit): \n";                 
	cin >> num;
	while (num != -1) 
	{
		arr[size] = num;
		size++;
		cin >> num;
	}

	cout << "Enter starting range index: \n";
	cin >> startindex;
	cout << "Enter ending range index: \n";
	cin >> endindex;

	for (int i = startindex; i < endindex; i++) 
	{
		search = arr[i];
		c = 0;
		found = false;

		for (int j = i; j < endindex; j++) 
		{
			if (arr[j] == search)
			{
				c++;
			}
		}
		PrimeFrequency(c, search);
	}

	system("pause");
	return 0;

}

void PrimeFrequency(int c, int search)
{
	int check = 0;
	bool found = true;
	check = c / 2;

	if (c == 0 || c == 1)
	{
		found = false;
	}
	else 
	{
		for (int i = 2; i <= check; i++)
		{
			found = true;
			if (c % i == 0)                      
			{
				found = false;
				break;
			}
		}
	}


	if (found == true) 
	{
		cout << "The frequency of " << search << " is prime frequency which is " << c << "\n";
	}
}

