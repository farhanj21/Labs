#include <iostream>
#include <string>
using namespace std;

class Lambo
{
private:
	int capacity, seats, year, engine, frame;
	string ownername, colour;
public:
	Lambo()
	{
		ownername = "abcd";
		colour = "white";
		capacity = 1000;
		seats = 4;
		year = 2012;
		engine = 100;
		frame = 5;
	}

	void Print()
	{
		cout << "Owner Name: " << ownername << "\n";
		cout << "Colour: " << colour << "\n";
		cout << "Cubic Capacity: " << capacity << "\n";
		cout << "Number of Seats: " << seats << "\n";
		cout << "Year: " << year << "\n";
		cout << "Engine Number: " << engine << "\n";
		cout << "Frame Number: " << frame << "\n";
	}
	
	Lambo(Lambo &Lambo)
	{
		ownername = Lambo.ownername;
		colour = Lambo.colour;
		capacity = Lambo.capacity;
		seats = Lambo.seats;
		year = Lambo.year;
		engine = Lambo.year;
		frame = Lambo.frame;
	}

	void setName(string inName)
	{
		ownername = inName;
	}
	void setYear(int inYear)
	{
		year = inYear;
	}
	void setEngine(int inEngine)
	{
		engine = inEngine;
	}
	void setFrame(int inFrame)
	{
		frame = inFrame;
	}

};

int main()
{
	string ownername;
	int engine, year,frame;

	Lambo obj1;
	
	
	cout << "Information aboout Obj1\n";
	obj1.Print();

	cout << "\nEnter Name\n";
	cin >> ownername;
	cout << "Enter Year\n";
	cin >> year;
	cout << "Enter Engine model\n";
	cin >> engine;
	cout << "Enter frame number\n";
	cin >> frame;
	obj1.setName(ownername);
	obj1.setYear(year);
	obj1.setEngine(engine);
	obj1.setFrame(frame);

	Lambo obj2(obj1);
	cout << "Information aboout Obj2\n";
	obj2.Print();




	system("pause");
	return 0;
}

