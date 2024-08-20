#include <iostream>
using namespace std;

int main()
{
	int sum = 0;

	for (int i = 500; i < 3000; i++)
	{
		if ((i % 3 == 0) && (i % 5 != 0))                         //the question states to find the sum for multplies of 3 and 5 but not both
		{
			sum = sum + i;                                           
		}
		else if ((i % 5 == 0) && (i % 3 != 0))
		{
			sum = sum + i;
		}
	}

	cout << "The sum of numbers below 3000 and above 500 which are multplies of 5 and 3 are " << sum << "\n";

	system("pause");
	return 0;

}