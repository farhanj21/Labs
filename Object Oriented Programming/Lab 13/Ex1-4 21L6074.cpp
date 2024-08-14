#include<iostream>
#include<cstring>
using namespace std;

class Shape
{
	string shapeName;

public:
	Shape()
	{

	}
	Shape(string name)
	{
		shapeName = name;
	}
	~Shape()
	{
		cout << "Shape Destructor Called\n";
	}
	virtual void print()
	{
	}
	virtual void GetInfo()
	{
		cout << "I am  a Base Class\n";
	}
	string getType()
	{
		return shapeName;
	}
};

class Square : public Shape
{
private:
	double length;
public:
	Square(string name, double len):Shape(name)
	{
		length = len;
	}
	~Square()
	{
		cout << "Square Destructor Called\n";
	}
	void print()
	{
		cout << "Name of Shape: " <<  getType() << "\n";
		cout << "Area: " << length * length << "\n";
	}
	void GetInfo()
	{
		cout << "I am  a Derived Class\n";
	}
};

class Rectangle : public Shape
{
private:
	double length;
	double width;
public:
	Rectangle(string name, double len, double wid):Shape(name)
	{
		length = len;
		width = wid;
	}
	~Rectangle()
	{
		cout << "Rectangle Destuctor Called\n";
	}
	void print()
	{
		cout << "Name of Shape: " << getType() << "\n";
		cout << "Area: " << length * width << "\n";

	}
};

Shape* CreateSquare(string ShapeName, int length) 
{
	return new Square(ShapeName, length);
}

Rectangle* CreateRectangle(string ShapeName, int len, int wid) 
{
	return new Rectangle(ShapeName, len, wid);
}

int main()
{


	Square s1("Quadliteral", 4);
	Shape* shape_ptr = &s1;
	shape_ptr->print();
	Shape s("Circle");
	Square* square_ptr = (Square*)(&s);
	Rectangle* rec_ptr = (Rectangle*)(&s);
	square_ptr -> print();
	rec_ptr -> print();
	Shape* quad = CreateSquare("Quadliteral", 4);
	Square* sq = dynamic_cast <Square*> (quad);
	if (sq) 
	{

		sq->print();
	}
	Rectangle* rect = CreateRectangle("Quadliteral", 4, 5);
	Shape* quad1 = dynamic_cast <Shape*> (rect);
	Square* sq1 = dynamic_cast <Square*> (quad1);
	if (sq1 == NULL) 
	{
		cout << "Invalid casting.\n";
	}

	Shape obj1("Circle");
	Square obj2("Quadliteral", 8);
	obj1.GetInfo();
	obj2.GetInfo();

	system("pause");
	return 0;
}
