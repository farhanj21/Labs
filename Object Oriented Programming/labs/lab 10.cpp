#include <iostream>
#include <conio.h>
using namespace std;

class Animal
{
public:
	virtual const char* speak()
	{
		return "Speak() called\n";
	}
	virtual ~Animal()
	{
		cout << "~Animal() called\n";
	}

};

class Dog : public Animal
{
public:
	const char* speak()
	{
		return "Woof!\n";
	}
	~Dog()
	{
		cout << "~Dog() called\n";
	}
};

class Cat : public Animal
{
public:
	const char* speak()
	{
		return "Meow\n";
	}
	~Cat()
	{
		cout << "~Cat() called\n";
	}
};

class Sheep : public Animal
{
	const char* speak()
	{
		return "Bleat!\n";
	}
	~Sheep()
	{
		cout << "~Sheep() called\n";
	}
};

class Cow : public Animal
{
	const char* speak()
	{
		return "Moo!\n";
	}
	~Cow()
	{
		cout << "~Cow() called\n";
	}
};

class Horse : public Animal
{
	const char* speak()
	{
		return "Neighs!\n";
	}
	~Horse()
	{
		cout << "~Horse() called\n";
	}
};


int main()
{
	const int size = 5;
	Animal* myPets[size];

	int i = 0;
	while (i < size)
	{
		cout << "Press 1 for a Dog, 2 for a Cat , 3 for a Sheep , 4 for a Cow and 5 for a Horse\n";
		switch (_getch())
		{
		case '1':
			myPets[i] = new Dog;
			cout << "Dog added at position " << i << "\n";
			i++;
			break;
		case '2':
			myPets[i] = new Cat;
			cout << "Cat added at position " << i << "\n";
			i++;
			break;
		case '3':
			myPets[i] = new Sheep;
			cout << "Sheep added at position " << i << "\n";
			i++;
			break;
		case '4':
			myPets[i] = new Cow;
			cout << "Cow added at position " << i << "\n";
			i++;
			break;
		case '5':
			myPets[i] = new Horse;
			cout << "Horse added at position " << i << "\n";
			i++;
			break;
			
		default:
			cout << "Invalid input. Enter again." << "\n";
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << myPets[i]->speak() << "\n";
		delete myPets[i];
	}


	system("pause");
	return 0;
}
