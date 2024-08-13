#include "Employee.h"
#include <iostream>
using namespace std;

void Employee::CopyCString(char source[50], char destination[50])
{
	for (int i = 0; i < 50; i++)
	{
		destination[i] = source[i];
	}
}

Employee::Employee()
{
	totalEmp++;
	empID = totalEmp;
	name[0] = '\0';
	address[0] = '\0';
	department[0] = '\0';
}

Employee::Employee(char empName[50], char empDep[50], char empAddress[50])
{
	totalEmp++;
	empID = totalEmp;
	CopyCString(empName, name);
	CopyCString(empDep, department);
	CopyCString(empAddress, address);
}

int Employee::getTotalEmp()
{
	return totalEmp;
}

int Employee::getEmpID()
{
	return empID;
}

void Employee::setName(char empName[50])
{
	CopyCString(empName, name);
}

void Employee::setAddress(char empAddress[50])
{
	CopyCString(empAddress, address);
}

void Employee::setDepartment(char empDep[50])
{
	CopyCString(empDep, department);
}

char* Employee::getName()
{
	return name;
}

char* Employee::getAddress()
{
	return address;
}

char* Employee::getDepartment()
{
	return department;
}

void Employee::Display()
{
	cout << "ID: " << getEmpID() << "\n";
	cout << "Name: " << getName() << "\n";
	cout << "Department: " << getDepartment() << "\n";
	cout << "Address: " << getAddress() << "\n\n";
}

Employee::~Employee()
{
	cout << "Destructor called here" << "\n";
}

int Employee::totalEmp = 0;

