 //Q8 part 1
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
    int num, total;
    cout << "How many Fibonacci Numbers you want to ask: ";
    cin >> total;
    while (total > 0)
    {
        cout << "\nWhich fibonacci number do you want to ask: ";
        cin >> num;
        cout << "F" << num << " = " << fibonacci(num) << "\n";
        total = total--;
    }

    system("pause");
    return 0;
}

// Q8 Part 2
#include <iostream>
using namespace std;

int main()
{
    int T;
    int term1 = 0, term2 = 1, next = 0;
    cout << "Enter a number you want to print Fibonnaci Sequence upto\n";
    cin >> T;

    next = term1 + term2;

    cout << "The sequence up to " << T << " is 0 1 ";                    // the first 2 numbers in the fibonacci sequence is 0 and 1

    while (next <= T)
    {
        cout << next << " ";
        term1 = term2;
        term2 = next;
        next = term1 + term2;
    }
    cout << "\n";

    system("pause");
    return 0;
}

// Q8 part 3
#include <iostream>
using namespace std;

int main()
{
    int start, end, num1 = 0, num2 = 1, next = 0;
    cout << "Enter the range you want to print Fibonnacci Numbers between\n";
    cin >> start >> end;

    cout << "The Fibonacci numbers between the range are: ";

    while (next <= end)
    {
        if (next >= start && next <= end)				
        {
            cout << next << " ";
        }
        num1 = num2;
        num2 = next;
        next = num1 + num2;
    }
    cout << "\n";

    system("pause");
    return 0;
}

//Q8 part 4
#include <iostream>
using namespace std;
int main()
{
	long int sum = 0;
	long int term1 = 0, term2 = 1, next = 0;

	while (next <= 4000000)					
	{
		if (next % 2 == 0)					
		{
			sum = sum + next;
		}
		term1 = term2;
		term2 = next;
		next = term1 + term2;
	}
	cout << "The sum of all even numbers in the fibonacci sequence up till 4 million is: " << sum << "\n";

	system("pause");
	return 0;
}
