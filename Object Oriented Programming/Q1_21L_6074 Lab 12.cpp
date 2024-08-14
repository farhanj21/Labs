#include<iostream>
#include<string>
using namespace std;

class student
{
private:
	int rollNo;
public:
	student()
	{
		rollNo = 0;
	}
	void set_number(int x)
	{
		rollNo = x;
	}
	void PrintRollNumber()
	{
		cout << "Your roll no is " << rollNo << "\n";
	}
};

class Test :virtual public student
{
protected:
	float maths;
	float physics;
public:
	Test()
	{
		maths = 0;
		physics = 0;
	}
	void set_marks(float math, float phy)
	{
		maths = math;
		physics = phy;
	}
	int getTotal()
	{
		return maths + physics;
	}
	void PrintMarks()
	{
		PrintRollNumber();
		cout << "Your result is here:\n";
		cout << "Mahts: " << maths << "\n";
		cout << "Physics: " << physics << "\n";
	}

};

class sports : virtual public student
{
protected:
	float score;
public:
	sports()
	{
		score = 0;
	}
	void set_score(int x)
	{
		score = x;
	}
	int getScore()
	{
		return score;
	}
	void PrintScore()
	{
		cout << "Your PT score is " << score << "\n";
	}

};



class result :public sports, public Test
{
protected:
	float total;
public:
	result()
	{
		total = 0.0;
	}
	void display()
	{
		total = getTotal() + getScore();
		PrintMarks();
		PrintScore();
		cout << "Your total score is: " << total << "\n";
	}
};


int main()
{
	result harry;
	harry.set_number(4200);
	harry.set_marks(78.9, 99.5);
	harry.set_score(9);
	harry.display();

	system("pause");
	return 0;

}
