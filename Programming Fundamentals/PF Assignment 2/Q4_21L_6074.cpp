#include <iostream>
using namespace std;

int main()
{
	int N, product;
	int i = 0;
	bool found = false;

	cout << "Please enter a number you want to find three consecutive multiples of\n";
	cin >> N;

	while (found == false)
	{
		product = i * (i + 1) * (i + 2);
		if (N == product)
		{
			found = true;
			cout << "The consecutive multiples of " << N << " are " << i << " " << i + 1 << " and " << i + 2 << "\n";
		}
		else if (i > 99999)
		{
			found = true;
			cout << N << " has no consecutive multiples\n";
		}
		i++;
	}

	system("pause");
	return 0;
}