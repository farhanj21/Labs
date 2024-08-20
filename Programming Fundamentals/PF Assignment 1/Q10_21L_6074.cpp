#include<iostream>
using namespace std;

int main()
{

    int num1, num2, result;
    char op;
    cout << "Please enter any two numbers\n";
    cin >> num1 >> num2;
    cout << "\nPlease enter any operator\n";
    cin >> op;

    if (op == '+')
    {
        result = num1 + num2;
    }
    else if (op == '-')
    {
        result = num1 - num2;
    }
    else if (op == '*')
    {
        result = num1 * num2;
    }
    else if (op == '/')
    {
        result = num1 / num2;
    }
    else if (op == '%')
    {
        result = num1 % num2;
    }
    else
    {
        cout << "\nInvalid Operator\n";
    }

    cout << "\n" << num1 << op << num2 << "=" << result << "\n";

    system("pause");
    return 0;

}
