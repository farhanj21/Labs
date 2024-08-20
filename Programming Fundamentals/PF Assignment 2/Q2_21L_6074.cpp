#include <iostream>
using namespace std;

int main()
{
	int x = 100, y;
	while (x > 0)
	{
		cin >> y;
		if (y == 25)
			x--;
		else
			cin >> x;
		cout << "x = " << x << "\n";
	}
	system("pause");
	return 0;
}