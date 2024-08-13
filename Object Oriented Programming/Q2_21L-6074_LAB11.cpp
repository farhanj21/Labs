#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(){}

	Person(string name,int age)
	{
		this->name=name;
		this->age=age;
	}

	virtual void print()
	{
		cout << "\n";
		cout<<"Name: "<<name<<"\n";
		cout<<"Age: "<<age<<"\n";
	}
};

class Patient:public Person
{
private:
	string diseaseType;
	string recommendedMedicine;
public:
	Patient(){}

	Patient(string name,int age,string diseaseType,string recommendedMedicine):Person(name,age)
	{
		this->diseaseType=diseaseType;
		this->recommendedMedicine=recommendedMedicine;
	}
	
	void print()
	{
		Person::print();
		cout<<"Disease type: "<<diseaseType<<"\n";
		cout<<"Medicine: "<<recommendedMedicine<<"\n";
	}
};

class MedicarePatient:public Patient
{
private:
	string hospitalName;
	string wardName;
	int roomNumber;

public:
	MedicarePatient(){}

	MedicarePatient(string name,int age,string diseaseType,string recommendedMedicine,string hospitalName,string wardName,int roomNumber):Patient(name,age,diseaseType,recommendedMedicine
	){
		this->hospitalName=hospitalName;
		this->wardName=wardName;
		this->roomNumber=roomNumber;
	}
	
	void print()
	{
		Patient::print();
		cout<<"Hospital: "<<hospitalName<<"\n";
		cout<<"Ward: "<<wardName<<"\n";
		cout<<"Room number: "<<roomNumber<<"\n";
	}
};

int main()
{

	Person** p=new Person*[2];
	
	p[0]= new Patient("Walter",45,"Cancer","Chemotherapy");
	p[1]= new MedicarePatient("Ali",19,"Corona","Panadol","National Hospital","ICU Ward",21);


	for(int i=0;i<2;i++)
	{
		p[i]->print();
	}
	
	cout << "\n";


	system("pause");
	return 0;
}
