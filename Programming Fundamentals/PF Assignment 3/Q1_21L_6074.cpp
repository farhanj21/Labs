#include <iostream>
using namespace std;

int main()

{
    int x;
    char y = 'a';
    bool check = false;
    int array[100] = {};
    int size = 0;

    cout << "Enter values into Array(-1 to exit): \n";
    cin >> x;
    while (x != -1)
    {
        array[size] = x;
        size++;
        cin >> x;
    }


    cout << "Enter a number: ";
    cin >> x;

    for (int i = 0; i <= size - 3; i++)
    {
        for (int j = 1; j <= size - 2; j++)
        {
            for (int k = 2; k <= size - 1; k++)
            {
                if (array[i] + array[j] + array[k] == x)
                {
                    cout << y << ") " << array[i] << " + " << array[j] << " + " << array[k] << " = " << x << "\n";
                    y++;
                    check = true;
                }
            }
        }
    }

    if (check == false)

    {
        cout << "\nNo triplet found!\n";
    }

    system("pause");
    return 0;
}