#include <iostream>
using namespace std;

class myVector
{

private:

	int* arrayptr;
	int capacity;
	int currentsize;

public:

	myVector()
	{
		arrayptr = new int[2];
		capacity = 2;
		currentsize = 0;
	}
	
	myVector(int size)
	{
		capacity = size;
		arrayptr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arrayptr[i] = 0;
		}
		currentsize = 0;
	
	}
	myVector operator = (myVector& vect)
	{
		vect.capacity = capacity;
		vect.currentsize = currentsize;
		vect.arrayptr = new int[capacity];

		for (int i = 0; i < currentsize; i++)
		{
			vect.arrayptr[i] = arrayptr[i];
		}
	}

	void print()
	{
		for (int i = 0; i < currentsize; i++)
		{
			cout << "Index " << i << " is " << arrayptr[i] << "\n";
		}
	}

	void operator + (int x)
	{
		currentsize++;
		if (currentsize >= capacity)
		{
			capacity = capacity * 2;
		}
		
		int* temparr = new int[currentsize];
		for (int i = 0; i < currentsize - 1; i++)
		{
			temparr[i] = arrayptr[i];
		}

		arrayptr[currentsize - 1] = x;
	}
	
	void operator - (int x)
	{
		for (int i = x; i > 0; i--)
		{
		currentsize--;

		int* temparr = new int[currentsize];
				for (int i = 0; i < currentsize; i++)
				{		
					temparr[i] = arrayptr[i];
				}
		}
	}
	
	~myVector()
	{
		if (arrayptr)
		{
			delete[]arrayptr;
			arrayptr = NULL;
		}
	}

};


int main()
{
	myVector vect;

	vect.print();//

	vect + (1);
	vect + (2);
	vect + (3);
	vect + (4);
	vect + (5);
	vect.print();
	
	cout << "\n";
	
	vect - (1);
	vect - (2);
	vect.print();

	system("pause");
	return 0;

}
