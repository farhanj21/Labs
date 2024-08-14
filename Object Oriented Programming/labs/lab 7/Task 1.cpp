#include <iostream>
using namespace std;
  
class Triangle 
{
    int a, b, c;
  
public:
	Triangle()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	friend ostream& operator <<(ostream& cout, Triangle& t)
	{
		cout << "{" << t.a << "," << t.b << "," << t.c << "}\n";
	}
	friend istream& operator >>(istream& cin, Triangle& t)
	{
		cout << "Enter side 1: ";
		cin >> t.a;
		cout << "Enter side 2: ";
		cin >> t.b;
		cout << "Enter side 3: ";
		cin >> t.c;
		return cin;
	}
    bool operator==(const Triangle &t) ;
};
  
bool Triangle::operator==(const Triangle &t) 
{
    int count = 0;
    if ((a == t.a)|| (a == t.b)|| (a == t.c)) 
	{
        count++;
    }
    if ((b == t.a) || (b == t.b)|| (b == t.c)) 
	{
        count++;
    }
    if ((c == t.a) || (c == t.b) || (c == t.c)) 
	{
        count++;
    }
  
    if (count == 3) 
	{
        return false;
    }
  
    return true;
}
  

int countUniqueTriangles(Triangle arr[], int n)
{
  

    int uni = 0;
  
    for (int i = 0; i < n - 1; i++) {
  
        int count = 0;
  
        for (int j = i; j < n - 1; j++) 
		{
            if (arr[i] == arr[j + 1])
                count++;
        }
        if (count == n - 1 - i)
            uni++;
    }
  
    return uni + 1;
};
  

int main()
{
	int totaltriangles = 0;
	int unique =0, found = 0;
	int *count = new int[totaltriangles];

	cout << "Enter number of triangles to test\n";
	cin >> totaltriangles;
	Triangle* t1 = new Triangle [totaltriangles];

	for(int i =1;i<=totaltriangles;i++)
	{
		cout << "Enter sides of " << i << " Triangle:\n";
		cin >> t1[i];
	}
  
    cout << "Unique Triangles are " << countUniqueTriangles(t1, totaltriangles) << "\n";

	system("pause");
    return 0;
}
