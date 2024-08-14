#include <iostream>
using namespace std;

int main()
{
	int size, temp, insert;
	cout << "Enter size of array\n";
	cin >> size;
	
	
	int *arr = new int [size];
	
	cout << "Enter array\n";
	
	for (int i = 0; i<size;i++)
	{
		cin >> arr[i];
	}
	cout << "Array: ";
	for(int i =0; i<size;i++)
	{
		cout << arr[i] << " ";
	}
	
for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	cout << "\nSorted Array:";
	for(int i =0; i<size;i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << "\nInsert an Element\n";
	cin >> insert;
	arr[size++] = insert;

	for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	cout << "Array: ";
	for(int i =0; i<size;i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	system("pause");
	return 0;
	
}
