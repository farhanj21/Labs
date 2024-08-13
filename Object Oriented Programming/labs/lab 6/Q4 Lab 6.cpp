#include<iostream>
using namespace std;

class Polynomial
{
private:
	int totalTerms;
	int* coefficient;
	int* exponent; 

public:
	Polynomial(int n, int* a, int* b);
	Polynomial addition(Polynomial a);
	Polynomial addition(int x);
	void display();
	bool notZero();
	bool notEqual(Polynomial p2);
	
};

Polynomial::Polynomial(int x, int* a, int* b)
{
	totalTerms = x;
	coefficient = a;
	exponent = b;
}

Polynomial Polynomial::addition(int num)
{
	
	for (int i = 0; i < totalTerms; i++)
	{
		coefficient[i] += num;
	}
	

	Polynomial x(totalTerms, coefficient, exponent);
	return x;
}

Polynomial Polynomial::addition(Polynomial a)
{
	int n = a.totalTerms + totalTerms;

	for (int i = 0; i < totalTerms; i++)
	{
		for (int j = 0; j < a.totalTerms; j++)
		{
			if (exponent[i] == a.exponent[j])
			{
				n--;
			}
		}
	}
	int* coefficientf = new int[n];
	int* exponentp = new int[n];

	int i = 0, j = 0, k = 0;

	while (i != totalTerms || j != totalTerms)
	{
		if (i == totalTerms)
		{
			coefficientf[k] = a.coefficient[i];
			exponentp[k] = a.exponent[i];
			j++;
		}

		else if (j == a.totalTerms)
		{
			coefficientf[k] = coefficient[i];
			exponentp[k] = exponent[i];
			i++;
		}
		else if (exponent[i] > a.exponent[i])
		{
			coefficientf[k] = coefficient[i];
			exponentp[k] = exponent[i];
			i++;
		}
		else if (exponent[i] < a.exponent[j])
		{
			coefficientf[k] = a.coefficient[i];
			exponentp[k] = a.exponent[i];
			j++;
		}
		else
		{
			coefficientf[k] = coefficient[i] + a.coefficient[j];
			exponentp[k] = exponent[j];
			j++;
			i++;
		}

		k++;
	}

	Polynomial x(n, coefficientf, exponentp);
	return x;
}

void Polynomial::display()
{
	for (int i = 0; i < totalTerms; i++)
	{
		if (i != totalTerms - 1 && exponent[i] != 0)
		{
			cout << coefficient[i] << "x^" << exponent[i] << "+";
		}
		else if (exponent[i] != 0)
		{
			cout << coefficient[i] << "x^" << exponent[i];
		}
		else
		{
			cout << coefficient[i];
		}
	}
	cout << "\n";
}
bool Polynomial::notZero()
{
	if (totalTerms == 1 && coefficient[0] == 0)
	{
		return true;
	}
	return false;
}

bool Polynomial::notEqual(Polynomial p2)
{
	for (int i = 0; i < totalTerms; i++)
	{
		if (coefficient[i] == p2.coefficient[i] && exponent[i] == p2.exponent[i])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int coefficient_P1[] = { 1,2,5 };
	int exponent_P1[] = { 4,2,0 }; 
	int coefficient_P2[] = { 4,3 }; 
	int exponent_P2[] = { 6,2 }; 


	Polynomial P1(3, coefficient_P1, exponent_P1);
	Polynomial P2(2, coefficient_P2, exponent_P2);



	cout << "P1 = ";  P1.display(); 
	cout << "P2 = "; P2.display(); 
	
	
	if (P1.notZero())
	{
		cout << "P1 is zero\n";

	}
	
	
	if (P1.notEqual(P2))
	{
		cout << "P1 is Not Equal to P2\n";
		P1.addition(1);

		P1.display();
		
	}
	Polynomial P3 = P1.addition(P2);  
	
	cout << "P3 = ";	
	P3.display();
	




	P3 = P1.addition(2); 
	cout << "P3 = ";
	P3.display();


	system("pause");
	return 0;
	
	

}


