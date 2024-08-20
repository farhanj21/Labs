#include <iostream>
using namespace std;

int main()
{
    float weight, height, bmi;
    cout << "Please enter weight in Kilograms\n";
    cin >> weight;
    cout << "Please enter height in Metres\n";
    cin >> height;

    bmi = weight / (2 * height);

    cout << "Your Body Mass Index(BMI) is: " << bmi << "\n";

    system("pause");
    return 0;

}


