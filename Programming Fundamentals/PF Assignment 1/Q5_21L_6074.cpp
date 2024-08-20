#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3, largest, smallest, mid;
    cout << "Enter three numbers\n";
    cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3)
    {
        largest = num1;
    }
    else if (num2 > num1 && num2 > num3)
    {
        largest = num2;
    }
    else
    {
        largest = num3;
    }

    if (num1 < num2 && num1 < num3)
    {
        smallest = num1;
    }
    else if (num2 < num1 && num2 < num3)
    {
        smallest = num2;
    }
    else
    {
        smallest = num3;
    }

    if ((num1 == largest && num2 == smallest) || (num2 == largest && num1 == smallest))
    {
        mid = num3;
    }
    else if ((num2 == largest && num3 == smallest) || (num3 == largest && num2 == smallest))
    {
        mid = num1;
    }
    else
    {
        mid = num2;
    }

    cout << "\nThe numbers in ascending order are: " << smallest << " " << mid << " " << largest;
    cout << "\nThe numbers in descending order are: " << largest << " " << mid << " " << smallest << "\n";

}

