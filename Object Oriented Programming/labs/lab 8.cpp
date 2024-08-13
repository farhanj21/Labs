#include <iostream>
using namespace std;
class Style
{
private:
	char color[10];
	bool isFilled;
public:
	Style();
	Style(const char pogcolor[], bool status)
	{
		int i;
		for(i =0;pogcolor[i]!='\0';i++)
		{
			color[i] = pogcolor[i];
		}
		color[i] = '\0';
		isFilled = status;
		cout << "Style constructor called\n";
	}
    void SetColor(char pogcolor[])
	{
		int i;
		for(i =0;pogcolor[i]!='\0';i++)
		{
			color[i] = pogcolor[i];
		}
		color[i] = '\0';
	}
	void SetFilled(bool status)
	{
		isFilled = status;
	}
	
	void print()
	{
		cout << "Color is " << color;
		if(isFilled)
		{
			cout << "\nIt is filled\n";
		}
		else
			cout << "\nIt is filled\n";
	}
	
	~Style()
	{
		cout << "Style destructor called\n";
	}

};

class Point
{
private: 
	int x, y;

public:
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
		cout << "Point() called\n";
	}
	void Print()
	{
		cout << "(" << x << "," << y << ")\n";
	}
	~Point()
	{
		cout << "Point Destructor called\n";
	}
};

class Circle
{
	Point center;
	float radius;
	Style *st;

public:
	Circle(int x, int y, float r):center(x, y)
{ 

	cout << "Circle overloaded constructor called\n";
	radius = r;
	st = NULL;
}
	void Print()
	{
	cout << "Center Of the Circle is "; center.Print();
	cout << "Radius of the circle is " << radius << "\n";
	st->print();
	}
	void SetStyle(Style* x)
	{
		st = x;
	}
	void SetColor(char color1[])
	{
		st->SetColor(color1);
	}
	void SetFilled(bool choice)
	{
		st->SetFilled(choice);
	}
	~Circle()
	{
		cout << "Destructor for Circle Called\n";
	}

};

class Triangle
{
	Point A;
	Point B;
	Point C;
public:
	Triangle(int Ax, int Ay, int Bx, int By, int Cx, int Cy):A(Ax, Ay),B(Bx,By),C(Cx,Cy)
	{
		cout<< "Triangle overloaded constructor called\n";
	}
	void Print()
	{
	cout << "Point A:";
	A.Print();
	cout << "Point B:";
	B.Print();
	cout << "Point C:";
	C.Print();
	}
	~Triangle()
	{
		cout << "Destructor for Triangle Called\n";
	}
};


class Student
{
	char name[50];
	char roll[8];
	float cgpa;
	char* namearr;
	char* rollptr;

public:
	Student()
{
	namearr=new char[50];
	rollptr=new char[8];
	name[0] = '\0';
	roll[0] = '\0';
	cgpa = 0.00;
    }
	Student(char N[], char R[], float GP)
	{
	namearr = new char[50];
	rollptr = new char[8];
	
	for (int i = 0; N[i] != '\0'; i++)
	{
		name[i] = N[i];
	}
	for (int i = 0; R[i] != '\0'; i++)
	{
		roll[i] = R[i];
	}
	cgpa = GP;
}

	
	void DisplayStudents()
{
	cout << "Name:";
		for (int i = 0; name[i] != '\0'; i++)
		{
			cout << name[i];
		}
		cout << "(";
		for (int i = 0; roll[i] != '\0'; i++)
		{
			cout << roll[i];
		}
		cout << ")";
		cout << "\nCGPA is " << cgpa << endl;
}
	
	
void Setter(Student S1)
{
	if (name)
	{
		name[0] = '\0';
		roll[0] = '\0';
		cgpa = 0.00;	
	}
	for (int i = 0; S1.name[i] != '\0'; i++)
	{
		name[i] = S1.name[i];
	}
	for (int i = 0; S1.name[i] != '\0'; i++)
	{
		roll[i] = S1.roll[i];
	}
	cgpa = S1.cgpa;
}

char* GetName()
{
	namearr = name;
	return namearr;
}

float Getcgpa()
    {
	return cgpa;
    }
	
	
void input()
{
	cout << "Enter the name:";
	cin >> name;
	cout << "Enter roll number:";
	cin >> roll;
	cout << "Enter CGPA:";
	cin >> cgpa;
}

~Student()
{
	cout << "Student destructor called";
}
};




int main()
{
	Triangle t(1,2,3,4,5,6);
    t.Print();
	cout << "\n";
	Style s1("Blue", true);
	Style* style1=&s1; 
	Circle circle1(3,4,2.5);
	circle1.SetStyle(style1);
	circle1.Print();
	cout << "\n";
	Student ss1;
	ss1.input();
	ss1.DisplayStudents();
	Student s2("12L1111", "Hashim Amla", 3.99);
	Student s3("13L1121", "Virat Kohli", 3.45);
	Student s4("13L1126", "Quinton De Kock", 2.98);
	Student s5("14L1361", "Joe Root", 2.99);
	Student s6("14L1124", "Martin Guptill", 3.09);
	Student s7("15L1315", "Rohit Sharma", 3.19);
	s2.DisplayStudents();
	s3.DisplayStudents();
	s4.DisplayStudents();
	s5.DisplayStudents();
	s6.DisplayStudents();
	s7.DisplayStudents();


		
	system("pause");
	return 0;
}
