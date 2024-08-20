#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float p1x, p1y, p2x, p2y, p3x, p3y, length1, length2, length3;

	cout << "Enter coordinates for point 1\n";
	cin >> p1x >> p1y;

	cout << "\n\nEnter coordinates for point 2\n";
	cin >> p2x >> p2y;

	cout << "\n\nEnter coordinates for point 3\n";
	cin >> p3x >> p3y;

	cout << "\n\n";

	length1 = pow(p1x - p2x, 2) + pow(p1y - p2y, 2);

	length2 = pow(p2x - p3x, 2) + pow(p2y - p3y, 2);

	length3 = pow(p1x - p3x, 2) + pow(p1y - p3y, 2);

	cout << "Length 1: " << sqrt(length1) << "\nLength 2: " << sqrt(length2) << "\nLength 3: " << sqrt(length3) << "\n";

	cout << "\n";

	if (length3 == length1 + length2 || length2 == length1 + length3 || length1 == length3 + length2 && length1 != length2 && length1 != length3 && length3 != length2)
	{
		cout << "This triangle is both a right-angled and scalene triangle.\n\n";
	}

	else if (length3 == length1 + length2 || length2 == length1 + length3 || length1 == length3 + length2)
	{
		cout << "This triangle is a right-angled triangle.\n\n";
	}

	else if (length1 != length2 && length1 != length3 && length3 != length2)
	{
		cout << "This triangle is a scalene triangle.\n\n";
	}

	else
	{
		cout << "This triangle is neither a scalene nor a right-angled.\n\n";
	}

	system("pause");
	return 0;


}

