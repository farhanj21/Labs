////Q3 Part 1
#include <iostream>
using namespace std;
void distinct(int arr[], int totalelements, int DistinctArr[]);

int main()
{
    int arr[20];
    int x;
    int DistinctArr[20];
    int totalelements = 0;

    cout << "Enter values into array(-99 to exit)\n";
    for (int i = 0; i < 20; i++) 
    {
        cin >> x;
        if (x == -99) 
        {
            break;
        }  
        else 
        {
            arr[i] = x;
            totalelements++;
        }
    }

    distinct(arr, totalelements, DistinctArr);

    system("pause");
    return 0;
}

void distinct(int arr[], int totalelements, int DistinctArr[])
{
    bool flag;
    int c = 0;
    int temp;

    for (int i = 0; i < totalelements; i++)
    {
        flag = false;
        for (int j = 0; j < totalelements; j++)
        {
            if (DistinctArr[j] == arr[i])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            DistinctArr[c] = arr[i];
            c++;
        }
    }


    cout << "Distinct elements in the array are: ";
    for (int i = 0; i < c; i++)
    {
        cout << DistinctArr[i] << " ";
    }
    cout << "\n";
}

//Q3 part 2
#include <iostream>
using namespace std;
void unique(int arr[], int totalelements, int UniqueArr[]);

int main()
{
    int arr[20];
    int x;
    int UniqueArr[20];
    int totalelements = 0;

    cout << "Enter values into array(-99 to exit)\n";
    for (int i = 0; i < 20; i++)
    {
        cin >> x;
        if (x == -99)
        {
            break;
        }
        else
        {
            arr[i] = x;
            totalelements++;
        }
    }

    unique(arr, totalelements, UniqueArr);

    system("pause");
    return 0;
}

void unique(int arr[], int totalelements, int UniqueArr[])
{
    int i, j;
    int c = 0;

    for (i = 0; i < totalelements; i++)
    {
        for (j = 0; j < totalelements; j++)
        {
            if (arr[i] == arr[j] && i != j)
                break;
        }
        if (j == totalelements)
        {
            UniqueArr[c] = arr[i];
            c++;
        }
    }

    cout << "Unique elements in the array are: ";
    for (int i = 0; i < c ; i++)
    {
       cout << UniqueArr[i] << " ";
    }
       cout << "\n";

}

//Q3 Part 3
#include <iostream>
using namespace std;
void distinct(int arr[], int totalelements, int DistinctArr[]);
void unique(int arr[], int totalelements, int UniqueArr[]);

int main()
{
    int arr[20];
    int x;
    int DistinctArr[20];
    int UniqueArr[20];
    int totalelements = 0;

    cout << "Enter values into array(-99 to exit)\n";
    for (int i = 0; i < 20; i++) 
    {
        cin >> x;
        if (x == -99) 
        {
            break;
        }  
        else 
        {
            arr[i] = x;
            totalelements++;
        }
    }
 
    distinct(arr, totalelements, DistinctArr);
    unique(arr, totalelements, UniqueArr);

    system("pause");
    return 0;
}

void distinct(int arr[], int totalelements, int DistinctArr[])
{
    bool flag;
    int c = 0;
    int temp;

    for (int i = 0; i < totalelements; i++)
    {
        flag = false;
        for (int j = 0; j < totalelements; j++)
        {
            if (DistinctArr[j] == arr[i])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            DistinctArr[c] = arr[i];
            c++;
        }
    }

    for (int i = 0;i < c;i++)
    {
        for (int j = i + 1;j < c;j++)
        {
            if (DistinctArr[i] > DistinctArr[j])
            {
                temp = DistinctArr[i];
                DistinctArr[i] = DistinctArr[j];
                DistinctArr[j] = temp;
            }
        }
    }

    cout << "Distinct elements in Increasing Order are: ";
    for (int i = 0; i < c; i++)
    {
        cout << DistinctArr[i] << " ";
    }
    cout << "\n";
}

void unique(int arr[], int totalelements, int UniqueArr[])
{
    int i, j,temp;
    int c = 0;

    for (i = 0; i < totalelements; i++)
    {
        for (j = 0; j < totalelements; j++)
        {
            if (arr[i] == arr[j] && i != j)
                break;
        }
        if (j == totalelements)
        {
            UniqueArr[c] = arr[i];
            c++;
        }
    }

    for (int i = 0;i < c;i++)
    {
        for (int j = i + 1;j < c;j++)
        {
            if (UniqueArr[i] < UniqueArr[j])
            {
                temp = UniqueArr[i];
                UniqueArr[i] = UniqueArr[j];
                UniqueArr[j] = temp;
            }
        }
    }

    cout << "Unique elements in the Decreasing Order are: ";
    for (int i = 0; i < c ; i++)
    {
       cout << UniqueArr[i] << " ";
    }
       cout << "\n";

}