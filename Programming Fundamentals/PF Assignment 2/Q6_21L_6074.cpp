#include <iostream>
using namespace std;

bool prime(int num)
{
    bool PrimeFlag = true;

    if (num == 0 || num == 1)
    {
        PrimeFlag = false;
    }
    else 
    {
        for (int i = 2; i <= num / 2; ++i)
        {
            if (num % i == 0)
            {
                PrimeFlag = false;
            }
        }
    }
    return PrimeFlag;
}

int main() 
{
    int num, H;

    cout << "Enter how many numbers you want to check prime for\n";
    cin >> H;

    for (int c = 1; c <= H; c++) 
    {
        cout << "Enter any positive number\n";
        cin >> num;

        if (prime(num))
            cout << num << " is a prime number\n";
        else
            cout << num << " is not a prime number\n";
    }

    system("pause");
    return 0;
}
