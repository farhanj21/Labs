#include <iostream>
using namespace std;

int main()
{
    int num
    int d1, d2, d3, d4, d5, d6;
    int sum = 0;
    cout << "Please enter a six digit number" << endl;
    cin >> num;

    d1 = num % 10;
    sum = sum + d1;

    num = num / 10;
    d2 = num % 10;
    sum = sum + d2;
    
    num = num / 10;
    d3 = num % 10;
    sum = sum + d3;

    num = num / 10;
    d4 = num % 10;
    sum = sum + d4;

    num = num / 10;
    d5 = num % 10;
    sum = sum + d5;

    num = num / 10;
    d6 = num % 10;
    sum = sum + d6;   
    
    cout << "The sum of the digits is " << sum << endl;

    system("pause");
    return 0;
    
}

