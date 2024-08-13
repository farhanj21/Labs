#include "Header.h"
#include "Employee.h"
#include <iostream>
using namespace std;

int main()
{
	Date date1;

	cout << "Default Constructor called : \n";
	date1.Print();
	cout << "\n";

	cout << "Overloaded Constructor called : \n";
	Date independenceDay(14,8,2018);
	independenceDay.Print();
	cout << "\n";

	cout << "Destructor called here \n\n";
	
	date1.Input();
	date1.Print();
	cout << "\n";

	cout << "Default Xmas Day:\n";
	Date xmasDay;
	xmasDay.Print();
	cout << "Set Xmas Day:\n";
	xmasDay.SetDay(25);
	xmasDay.SetMonth(12);
	xmasDay.SetYear(2018);
	xmasDay.Print();
	cout << "Xmas Day using Getters:\n";
	cout << xmasDay.GetDay() << "/" << xmasDay.GetMonth() << "/" << xmasDay.GetYear() << "\n";

	Date temp;
	temp = xmasDay;
	cout << "Xmas Day using temp:\n";
	temp.Print();
	cout << "\n";

	cout << "Comparing\n";
	cout << xmasDay.Compare(date1);
	cout << "\n"; 

	cout << "Increment test\n";
	date1.Print();
	date1.IncrementMonth();
	cout << "\n\n";

	cout << "Question 2\n";

	int size;
	char data[50];
	
	cout << "Enter number of employees:\n";
	cin >> size;
	Employee* arr = new Employee[size];
	cin.getline(data, 50);

	for (int i = 0; i < size; i++)
	{
		cout << "Enter name of Employee " << i + 1 << "\n";
		cin.getline(data, 50);
		arr[i].setName(data);

		cout << "Enter address of Employee " << i + 1 << "\n";
		cin.getline(data, 50);
		arr[i].setAddress(data);

		cout << "Enter department of Employee " << i + 1 << "\n";
		cin.getline(data, 50);
		arr[i].setDepartment(data);
	}

	cout << "\nThe data of all the employees:\n";

	for (int i = 0; i < size; i++)
	{
		arr[i].Display();
	}

	cout << "Destructor called here\n";


	system("pause");
	return 0;
}