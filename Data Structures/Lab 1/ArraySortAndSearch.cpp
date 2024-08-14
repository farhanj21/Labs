#include <iostream>
using namespace std;

int main()
{
	int size, temp, search;
	bool flag = false;
	cout << "Enter size of array\n";
	cin >> size;
	
	
	int *arr = new int [size];
	
	cout << "Enter array\n";
	
	for (int i = 0; i<size;i++)
	{
		cin >> arr[i];
	}
	
	for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	cout << "Sorted Array: ";
	for(int i =0; i<size;i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << "\nSearch an Element\n";
	cin >> search;
	for(int i = 0; i<size;i++)
	{
		if (arr[i] == search)
		{
			cout << "The searched element is present on index " << i << "\n";
			flag = true;
		}	
	}
		if(flag == false)
		{
			cout << "The searched element does not exist in the array\n";
		}
	
	cout << "\n";
	system("pause");
	return 0;
	
}
