#include<iostream>

using namespace std;

int main()
{
	int num1, num2, num3, a1, b1, c1;
	cout << "Please enter any three numbers\n";
	cin >> num1 >> num2 >> num3;

	a1 = num1 * num1;
	b1 = num2 * num2;
	c1 = num3 * num3;

	if ((a1 == b1 + c1) || (b1 == a1 + c1) || (c1 == a1 + b1))
	{
		cout << "The numbers entered are Pythagorean Triple\n";
	}
	else
	{
		cout << "The numbers entered are not Pythagorean Triples!\n";
	}

	system("pause");
	return 0;
}
