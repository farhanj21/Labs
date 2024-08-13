#include <iostream>
using namespace std;
int main()
{
	int numOfItems;
	double unitCost;

	try
	{
		cout << "Enter the number of items\n";
		cin >> numOfItems;
		cout << "\n";

		if (numOfItems < 0)
			throw numOfItems;
		cout << "Enter the cost of one item\n";
		cin >> unitCost;
		cout << "\n";

		if (unitCost < 0)
			throw unitCost;
		cout << "Total cost : $" << numOfItems * unitCost << "\n";

	}
	catch (int num)
	{
		cout << "negative number of items " << num << "\n";
		cout << " Number of items must be nonnegative.\n";

	}
	catch (double dec)
	{
		cout << "negative unit cost " << dec << "\n";
		cout << "unit cost must be nonnegative";

	}

	system("pause");
	return 0;
}
