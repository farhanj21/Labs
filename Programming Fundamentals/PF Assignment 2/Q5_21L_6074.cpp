#include<iostream>
using namespace std;

int main()
{
    int num = 0;
    int even = 0;
    int odd = 0;

    cout << "Please enter numbers\n";

    while (num != -1)
    {
        cin >> num;
        if (num % 2 == 0)
            even = even + 1;
        else
            odd = odd + 1;
    }
    cout << "\nThe frequency of odd numbers is " << odd << "\n";
    cout << "The frequency of even numbers is " << even << "\n";

    system("pause");
    return 0;

}

