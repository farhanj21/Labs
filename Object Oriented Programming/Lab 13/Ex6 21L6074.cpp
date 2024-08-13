#include<iostream>
#include<string>

using namespace std;

class tornadoException
{
private:

	string message;

public:

	tornadoException()
	{

		message = "Take cover immediately";

	}
	tornadoException(int m)

	{
		message = "Tornado: m miles away and approcahing\n";

	}

	string what()
	{
		return message;
	}

};

int main()
{
	int miles;

	try 
	{
		cout << "Enter distance in miles\n";
		cin >> miles;

		if (miles <= 0) 
		{
			throw tornadoException();
		}
		else
		{
			throw tornadoException(miles);
		}
	}

	catch (tornadoException exceptiontest)
	{
		cout << "Tornado Exception " << "\n";
		cout << exceptiontest.what();
	}

	cout << "\n";
	system("pause");
	return 0;
}
