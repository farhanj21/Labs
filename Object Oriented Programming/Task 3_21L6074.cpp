#include <iostream>
using namespace std;

#define size 5

class Student
{
	int* marksArr;

public:

	Student()
	{
		marksArr = new int[size];
	}

	Student(Student& obj)
	{
		marksArr = new int[size];
		copyMarks(obj);

	}

	void copyMarks(Student& obj)
	{
		for (int i = 0; i < size; i++)
		{
			marksArr[i] = obj.marksArr[i];
		}
	}

	void Display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << *(marksArr + i) << ",";
		}
		cout << "\n";
	}

	void set_marks(int mark, int count)
	{
		if (count < 0 || count >= size)
		{
			cout << "Index is invalid\n";
		}
		else
		{
			*(marksArr + count) = mark;
		}
	}

	

	~Student()
	{

	}


};

int main()
{
	int mark;
	Student s1;

	cout << "Enter marks of student 1 for 5 subjects\n";

	for (int i = 0; i < size; i++)
	{
		cin >> mark;
		s1.set_marks(mark, i);
	}

	cout << "Student 1 marks: ";
	s1.Display();

	Student s2 = s1;
	cout << "Student 2 marks: ";
	s2.Display();

	s1.set_marks(69, 2);


	cout << "Student 1 marks after change: ";
	s1.Display();
	cout << "Student 2 marks after change: ";
	s2.Display();

	cout << "Now the error is corrected as it copies separately\n";

	

	system("pause");
	return 0;
}