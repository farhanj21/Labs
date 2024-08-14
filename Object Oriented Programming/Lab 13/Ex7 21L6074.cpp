#include <iostream>
using namespace std;

class InvalidDay
{
private:
	string message;
public:
	InvalidDay()
	{
		message = "Invalid day";
	}
	void showError()
	{
		cout << message << "\n";
	}
};

class InvalidMonth
{
public:
	string message;
	InvalidMonth()
	{
		message = "Invalid Month";
	}
	void showError()
	{
		cout << message << "\n";
	}
};

class LeapYear
{
public:
	bool checkYear(int year)
	{
		return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	void showError(int year)
	{
		if (checkYear(year) == 1)
		{

		}
		else 
		{
			cout << "Invalid Year\n";
		}
	}
};

int inputData(int day, int month, int year)
{
	LeapYear leap;
	InvalidDay dayInvalid;

	int flag;

	if (day > 31)
	{
		InvalidDay dayInvalid;
		dayInvalid.showError();
		flag = 0;
	}
	else if (month > 12)
	{
		InvalidMonth monthInvalid;

		monthInvalid.showError();
		flag = 0;
	}
	else if (month == 2 && leap.checkYear(year) == 0 && day != 28) 
	{
		dayInvalid.showError();
		flag = 0;
	}
	else if (month == 2 && leap.checkYear(year) == 1 && day != 29) 
	{
		dayInvalid.showError();
		flag = 0;
	}
	else
	{
		flag = 1;
	}
	return flag;
}


int main() 
{
	string months[12] ={ "January","February","March","April","May","June","July","August","September","October","November","December" };

	int day = 0; 
	int month = 0;
	int year = 0;

	cout << "Enter month in numbers\n";
	cin >> month;

	cout << "Enter day in numbers\n";
	cin >> day;

	cout << "Enter year in numbers\n";
	cin >> year;

	while (inputData(day, month, year) == 0)
	{
		cout << "Enter day:\n";
		cin >> day;

		cout << "Enter month:\n";
		cin >> month;

		cout << "Enter year:\n";
		cin >> year;
	}

	cout << "Date of Birth: " << months[month - 1] << " " << day << "," << year << "\n";

	system("pause");
	return  0;

}
