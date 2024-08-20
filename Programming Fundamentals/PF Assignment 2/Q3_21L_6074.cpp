#include<iostream>
using namespace std;

int main()
{
    int height;
    char symbol = '*';
    cout << "Enter height: ";
    cin >> height;
    cout << "\n";

    for (int b = 1; b <= height; b++)
    {
        for (int c = 1; c <= b; c++)
        {
            cout << symbol;
        }
        cout << "\n";
    }
    for (int i = height-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    system("pause");
    return 0;

}

