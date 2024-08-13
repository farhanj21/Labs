#include<iostream> 
#include<string> 
#include<cmath>
using namespace std;


class Roundoff
{
private:
	double number;
public:
	Roundoff()
	{
		number = 0.0;
	}
	Roundoff(float num)
	{
		number = num;
	}
	friend ostream& operator << (ostream& cout, const Roundoff& c1)
	{
		cout << c1.number;
		return cout;
	}
	friend istream& operator >> (istream& cin, Roundoff& c1)
	{
		cin >> c1.number;
		return cin;
	}

	void operator++()
	{
		number = number + 1;
	}
	void operator++(int)
	{
		number--;    
		float x = number;
		int count = 0;
		
		while ((int)x != x)
		{
			x = x * 10; 
			count++;
		}
		number = number + (1.0 / pow(10, count));
	}

};

int main()
{
	double n1 ;
	cout << "Enter A Double Number \n";
	cin >> n1;

	Roundoff num(n1);
	++num;
    cout << "Prefix: " << num << "\n";
	num++;
	cout << "Postfix: " << num << "\n"; 
		
	system("pause");		
	return 0;
}
