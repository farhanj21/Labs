#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum = 0;
    cout << "Please enter a six digit number\n";
    cin >> num;

        while (num != 0) 
    {
        sum = sum + num % 10;
        num = num / 10;
    }
        cout << "The sum of the digits is " << sum << "\n";

    system("pause");
    return 0;
    
}

