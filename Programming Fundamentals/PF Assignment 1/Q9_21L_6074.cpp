#include<iostream>
using namespace std;

int main()
{
    char character;
    cout << "Enter any character\n";
    cin >> character;

    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
    {
        cout << character << " is an Alphabet\n";
    }
    else if (character >= '0' && character <= '9')
    {
        cout << character << " is a Digit\n";
    }
    else
    {
        cout << character << " is a Special Character\n";
    }

    system("pause");
    return 0;
}