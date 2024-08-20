#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Please two numbers\n";
    cin >> num1 >> num2;

    if (num1 % num2 == 0)
        cout << num1 << " is the multiple of " << num2 << "\n";
    else if
        (num2 % num1 == 0)
        cout << num2 << " is the multiple of " << num1 << "\n";
    else
        cout << "They are not multiples of each other\n";

    system("pause");
    return 0;


}
