#include <iostream>
using namespace std;

class Integer
{
	int integerarray[10];
	friend int largest(Integer x1);
	friend int smallest(Integer x1);
	friend void repeat(Integer x1);
	friend void sortarray(Integer &x1);
public:
	Integer()
	{
		initializeArray();
	}
	void initializeArray()
	{
		cout << "Enter values of array\n";
		for (int i = 0; i < 10; i++)
		{
			cin >> integerarray[i];
		}
	}
	void print()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << integerarray[i] << " ";
		}
	}
};

int largest(Integer x1)
{
	int largest = 0;
	for (int i = 0; i < 10; i++)
	{
		if (x1.integerarray[i] > largest)
		{
			largest = x1.integerarray[i];
		}
	}
	return largest;
}

int smallest(Integer x1)
{
	int smallest = 1000000;
	for (int i = 0; i < 10; i++)
	{
		if (x1.integerarray[i] < smallest)
		{
			smallest = x1.integerarray[i];
		}
	}
	return smallest;
}

void repeat(Integer x1)
{	
	bool found = false;
	for (int i = 0; i < 10; i++)
	{
			if (x1.integerarray[i] == x1.integerarray[i+1])
			{
				found = true;
			}
		if (found == true)
		{
			cout << x1.integerarray[i] << " has been repeated\n";
		}
	}
}

void sortarray(Integer &x1)
{
	int min;
	int temp;
	for (int i = 0; i < 9; i++)
	{
		min = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (x1.integerarray[j] < x1.integerarray[min])
			{
				min = j;
			}
		}
		temp = x1.integerarray[i];
		x1.integerarray[i] = x1.integerarray[min];
		x1.integerarray[min] = temp;
	}
}

int main()
{
	Integer x;
	cout << "The largest integer is " << largest(x) << "\n";
	cout << "The smallest integer is " << smallest(x) << "\n";
	repeat(x);
	sortarray(x);
	cout << "The sorted array in ascending order is: ";
	x.print();
	cout << "\n";
	system("pause");
	return 0;
	
}
