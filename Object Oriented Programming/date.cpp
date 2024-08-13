#include "Header.h"
#include <iostream>
using namespace std;

void Date::Print()
{
	cout << day << "/" << month << "/" << year << "\n";
}

void Date::Input()
{
	cout << "Please enter Day\n";
	cin >> day;
	while (day <= 0 || day > 31)
	{
		cout << "Invalid day\n";
		cin >> day;
	}
	cout << "Please enter Month\n";
	cin >> month;
	while (month <= 0 || month > 12)
	{
		cout << "Invalid month\n";
		cin >> month;
	}
	cout << "Please enter Year\n";
	cin >> year;
	

}

void Date::SetDay(int d)
{
	day = 25;
}
void Date::SetMonth(int m)
{
	month = 12;
}
void Date::SetYear(int y)
{
	year = 2018;
}

int Date::GetDay()
{
	return day;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetYear()
{
	return year;
}

int Date::Compare(Date d2)
{
	if (d2.year > year)
	{
		return 1;
	}
	else if (d2.year == year)
	{
		if (d2.month > month)
		{
			return 1;
		}
		else if (d2.month == month)
		{
			if (d2.day > day)
			{
				return 1;
			}
			else if (d2.day == day)
			{
				return 0;
			}
		}
	}
	else
	{
		return -1;
	}
}

void Date::IncrementMonth()
{
	month = month++;
	cout << day << "/" << month << "/" << year << "\n";
}