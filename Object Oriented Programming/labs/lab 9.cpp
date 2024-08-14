#include <iostream>
using namespace std;

class person
{
	char* firstname;
	char* lastname;

protected:
	int age;
public:

	person()
	{
		firstname = NULL;
		lastname = NULL;
		age = 0;
	}

	person(string first, string last, int personAge)
	{
		cout << "Person Constructor called\n";

		int size1 = first.length();
		int size2 = last.length();
		firstname = new char[size1];
		lastname = new char[size2];

		for (int i = 0; i < size1; i++)
		{
			firstname[i] = first[i];
		}

		for (int i = 0; i < size2; i++)
		{
			lastname[i] = last[i];
		}
		age = personAge;
	}

	void PrintPerson()
	{
		cout << "Name: ";
		for (int i = 0; i < firstname[i] != '\0'; i++)
		{
			cout << firstname[i];
		}
		cout << " ";
		for (int i = 0; i < lastname[i] != '\0'; i++)
		{
			cout << lastname[i];
		}

		cout << "\nAge: " << age << "\n";
	}

	~person()
	{
		cout << "Person Destructor called\n";
		delete[] lastname;
		delete[] firstname;

		firstname = NULL;
		lastname = NULL;
	}
};

class student :public person
{
	float gpa;

public:
	student()
	{
		gpa = 0.0;
	}

	student(string First, string Last, int personAge, float cgpa) : person(First, Last, personAge)
	{
		cout << "Student Constructor called\n";
		gpa = cgpa;
	}

	void PrintStudent()
	{
		PrintPerson();
		cout << "CGPA: " << gpa << "\n";
	}

	~student()
	{
		cout << "Student Destructor called\n";
	}
};

class faculty :public person
{
	int courseFaculty;
	long long facultyTelephone;

public:
	faculty()
	{
		courseFaculty = 0;
		facultyTelephone = 0;
	}
	faculty(string First, string Last, int personAge, int courseCount, long long telephone) :person(First, Last, personAge)
	{
		cout << "Faculty Constructor called\n";
		courseFaculty = courseCount;
		facultyTelephone = telephone;

	}
	void Printfaculty()
	{
		PrintPerson();

		cout << "\nCourse Count: " << courseFaculty << endl;
		cout << "Telephone: " << facultyTelephone << endl;;
	}
	~faculty()
	{
		cout << "Faculty Destructor called\n";
	}
};

class graduate :public student
{

	char* func;

public:

	graduate(string First, string Last, int personAge, float  cgpa, string function) : student(First, Last, personAge, cgpa)
	{
		cout << "Graduate Constructor called\n";
		int size = function.length();
		func = new char[size];
		for (int i = 0; i < size; i++)
		{
			func[i] = function[i];
		}

	}
	void printgraduate()
	{
		PrintStudent();

		cout << "Attribute: ";

		for (int i = 0; i < func[i] != '\0'; i++)
		{
			cout << func[i];
		}
		cout << "\n";
	}
	~graduate()
	{
		cout << "Graduate Destructor called\n";
		delete[] func;
		func = NULL;
	}
};

class undergraduate :public student
{
	char* topic;

public:


	undergraduate(string First, string Last, int personAge, float  cgpa, string function) : student(First, Last, personAge, cgpa)
	{
		cout << "Undergraduate Constructor called\n";

		int size = function.length();
		topic = new char[size];
		for (int i = 0; i < size; i++)
		{
			topic[i] = function[i];
		}

	}
	void printundergraduate()
	{
		PrintStudent();

		cout << "Attribute:";

		for (int i = 0; i < topic[i] != '\0'; i++)
		{
			cout << topic[i];
		}
		cout << "\n";
	}
	~undergraduate()
	{
		cout << "Undergraduate Destructor called\n";
		delete[] topic;
		topic = NULL;
	}
};

int main()
{
	person p1("Ted", "Thompson", 22);
	p1.PrintPerson();

	cout << "\n";

	student s1("Ted", "Thompson", 22, 4.0);
	s1.PrintStudent();

	cout << "\n";

	undergraduate u1("Ted", "Thompson", 22, 3.91, "The Event Locator");
	graduate g1("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");

	u1.printundergraduate();
	cout << "\n";
	g1.printgraduate();
	cout << "\n";
	u1.PrintStudent();

	faculty f1("Ted", "Thompson", 22, 5, 923174532990);
	f1.Printfaculty();


	system("pause");
	return 0;
}
