#include <iostream>
using namespace std;


class matrix
{
	int** arr;
	int N;


public:

	matrix()
	{
		arr = nullptr;
		N = 0;
	}
	
	friend istream& operator >> (istream& cin, matrix& arr)
	{
		arr.arr = new int*[arr.N];
		for (int i = 0; i < arr.N; i++)
		{
			arr.arr[i] = new int[arr.N];
			for (int j = 0; j < arr.N; j++)
			{
				cin >> arr.arr[i][j];
			}
		}
		return cin;
	}
	friend ostream& operator << (ostream& cout, matrix& arr)
	{
		
		for (int i = 0; i < arr.N; i++)
		{
			for (int j = 0; j < arr.N; j++)
			{
				cout<< arr.arr[i][j]<<" ";
				
			}
			cout << "\n";
		}
	
		return cout;
	}
	


	matrix operator +(const matrix& m2)
	{
		matrix temp;
		temp.N = N;
		temp.arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			temp.arr[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				temp.arr[i][j]= arr[i][j] + m2.arr[i][j];
			}
		}

		return temp;
	}
	matrix operator -(const matrix& m2)
	{
		matrix temp;
		temp.N = N;
		temp.arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			temp.arr[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				temp.arr[i][j] = arr[i][j] - m2.arr[i][j];
			}
		}

		return temp;
	}
	matrix operator *(const matrix& m2)
	{
		matrix temp;
		temp.N = N;
		temp.arr = new int*[N];
	
		
		for (int i = 0; i < N; i++)
		{
			temp.arr[i] = new int[N];
			for (int j = 0; j < N; j++) 
			{
				temp.arr[i][j] = 0;
				for (int k = 0; k < N; k++) 
				{
					
					temp.arr[i][j] += arr[i][k] * m2.arr[k][j];
				}
			}
		}

	  return temp;
	}

    void sizearr(int x)
	{
		N = x;
	}



};

int main()
{
	int N;
	matrix m1, m2;

	cout << "Enter size of matrix\n";
	cin >> N;

	m1.sizearr(N);
	m2.sizearr(N);

	cout << "Enter elements for Matrix 1:\n";
	cin >> m1;
	cout << "Enter elements for Matrix 2:\n";
	cin >> m2;
	
	
	cout << "Matrix 1:\n";
	cout << m1;
	cout << "Matrix 2:\n";
	cout << m2;


	matrix m3;
	m3 = m1 + m2;
	cout << "Addition of given matrices is:\n";
	cout << m3;

	m3 = m1 - m2;
	cout << "Subtraction of given matrices is:\n";
	cout << m3;

	m3 = m1 * m2;
	cout << "Multiplication of given matrices is:\n";
	cout << m3;

	system("pause");
	return 0;
}

