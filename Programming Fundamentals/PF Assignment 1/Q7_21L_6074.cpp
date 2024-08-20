#include <iostream>
using namespace std;

int main()
{
    int A, B, temp;
    cout << "Please enter any two numbers\n";
    cin >> A >> B;
    cout << "\nBefore Swapping: " << "A = " << A << "    " << "B = " << B;
    temp = A;
    A = B;
    B = temp;
    cout << "\nAfter Swapping: " << "A = " << A << "    " << "B = " << B << "\n";

    system("pause");
    return 0;
}

// the code below is for swapping without use of third variable

#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cout << "Please enter any two numbers\n";
    cin >> A >> B;
    cout << "\nBefore Swapping: " << "A = " << A << "    " << "B = " << B;

    A = A + B;
    B = A - B;
    A = A - B;

    cout << "\nAfter Swapping: " << "A = " << A << "    " << "B = " << B << "\n";

    system("pause");
    return 0;
}




