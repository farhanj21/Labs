//Q4 part 1
#include <iostream>
using namespace std;

int main()
{
	int arr[100] = { 0 };
	int x = 0;
	int totalelements = 0;
	int temp;
	int size = sizeof(arr);

	cout << "Enter only binary numbers into array(-1 to exit)\n";

	for (int i = 0; i < size; i++)
	{
		cin >> x;
		while (x != 0 && x != 1 && x != -1)              
		{
			cout << "Invalid Input(Please enter only 0 or 1)\n";
			cin >> x;
		}
		if (x != -1)                                  
		{
			arr[i] = x;
		}
		else
		{
			totalelements = i;
			break;
		}
	}

	for (int i = 0; i < totalelements; i++)
	{
		for (int j = 0; j < totalelements - 1; j++)
		{
			if (arr[j] > arr[j + 1])                                  
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "Array after moving Zeros to the left: ";
	for (int j = 0; j < totalelements; j++)
	{
		cout << arr[j] << " ";
	}

	cout << "\n";
	system("pause");
	return 0;
}

//Q4 part 2
#include<iostream>
using namespace std;

int main()
{
    char fruits[100];
    char temp;
    int i, j;
    int flag;
    int size = sizeof(fruits);

    cout << "Please enter list of fruits(a for Apple, b for Banana and m for Mango)\n";

    for (int i = 0;i < size;i++)
    {
        cin >> fruits[i];
        while (fruits[i] != 'a' && fruits[i] != 'b' && fruits[i] != 'm' && fruits[i] != '-')             
        {
            cout << "Invalid Input(Please enter only a, b or m)\n";
            cin >> fruits[i];
        }
        if (fruits[i] != '-')
        {
            fruits[i] = fruits[i];
        }
        else
        {
            size = i;
            break;
        }
    }


    for (i = 0;i < size;i++)                                 
    {
        flag = 0;
        if (fruits[i] != 'b')
        {
            temp = fruits[i];
            for (j = i + 1;j < size;j++)
            {
                if (fruits[j] == 'b')
                {
                    flag = 1;
                    break;
                }

            }
            if (flag == 1)
            {
                fruits[i] = fruits[j];
                fruits[j] = temp;
            }

        }
    }

    for (i = 0;i < size;i++)                                
    {
        flag = 0;
        if (fruits[i] != 'm' && fruits[i] != 'b')
        {
            temp = fruits[i];
            for (j = i + 1;j < size;j++)
            {
                if (fruits[j] == 'm')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                fruits[i] = fruits[j];
                fruits[j] = temp;
            }
        }

    }

    cout << "Array after moving b to the beginning, then m and a: ";                    
    for (int i = 0;i < size;i++)
    {
        cout << fruits[i] << " ";
    }

    cout << "\n";
    system("pause");
    return 0;
}