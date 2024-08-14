#include <iostream>
using namespace std;

int fibonacci(int num)
{
    if (num <= 1)
    {
    	return num;
	}
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
	int num;
	cout << "Enter a number\n";
	cin >> num;
	
	cout << "Fibonacci number is " << fibonacci(num) << "\n";
	
	system("pause");
	return 0;
}
