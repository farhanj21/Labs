#include <iostream>
using namespace std;

int main()
{
	int size, temp, search;
	cout << "Enter size of array\n";
	cin >> size;
	
	
	int *arr = new int [size];
	
	cout << "Enter array\n";
	
	for (int i = 0; i<size;i++)
	{
		cin >> arr[i];
	}
	
    int check, j; 
    for (int i = 1; i < size; i++)
    { 
        check = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > check)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = check; 
    } 
	
	cout << "Sorted Array:";
	for(int i =0; i<size;i++)
	{
		cout << arr[i] << " ";
	}
	

	
	
	cout << "\n";
	system("pause");
	return 0;
	
}
