using namespace std;

#define size_address 50
#define size_name 50
#define size_department 50

class Employee {

private:
	static int totalEmp;
	int empID;
	char name[size_name];
	char address[size_address];
	char department[size_department];;

public:
	void CopyCString(char source[50], char destination[50]);
	Employee();
	Employee(char empName[50], char empDep[50], char empAddress[50]);
	int getTotalEmp();
	int getEmpID();
	void setName(char empName[50]);
	void setAddress(char empAddress[50]);
	void setDepartment(char empDep[50]);
	char* getName();
	char* getAddress();
	char* getDepartment();
	void Display();
	~Employee();
};

