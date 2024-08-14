#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Computer
{
private:
	string company;
	float price;
public:
	Computer(){}

	Computer(string company,float price)
	{
		this->company=company;
		this->price=price;
	}
	
	virtual void show()
	{
		cout<<"Company name: "<<company<<"\n";
		cout<<"Company price: "<<price<<" dollars\n";
	}
};


class Desktop: public Computer
{
private:
	string colour;
	float size;
	string processor;
public:
	Desktop (){}

	Desktop (string company,float price,string colour,float size,string processor):Computer(company,price)
	{
		this->colour=colour;
		this->size=size;
		this->processor=processor;
	}


	virtual void show()
	{
		Computer::show();
		cout<<"Desktop colour: "<<colour<<"\n";
		cout<<"Desktop monitor size: "<<size<<" inch\n";
		cout<<"Desktop processor type: "<<processor<<"\n";
	}
};


class Laptop : public Computer
{
private:
	string colour;
	float size;
	string processor;
public:
	Laptop(){}
	
	Laptop  (string company,float price,string colour,float size,string processor):Computer(company,price)
	{
		this->colour=colour;
		this->size=size;
		this->processor=processor;
	}
	
	virtual void show()
   {
		Computer::show();
		cout<<"Laptop colour: "<<colour<<"\n";
		cout<<"Laptop size: "<<size<<" inch\n";
		cout<<"Laptop processor type: "<<processor<<"\n";
	}
};


int main()
{
	Computer* c1;
	
	cout << "Desktop:\n";
	Desktop* desktop=new Desktop("AMD",1500,"Black",24,"Ryzen 5 3600");
	c1=desktop;
	c1->show();

	cout<<"\nLaptop:\n";
	Laptop* laptop=new Laptop("Acer",700,"White+Black",17,"i7-6500U");
	c1=laptop;
	c1->show();
	
	cout<<"\n";

	system("pause");
	return 0;
}

