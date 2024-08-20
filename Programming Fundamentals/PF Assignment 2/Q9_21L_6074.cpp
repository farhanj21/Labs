#include <iostream>
using namespace std;

int main()
{
	int bDay, bMonth, bYear;
	int cDay, cMonth, cYear;
	int ageday, agemonth, ageyear;

	cout << "Enter date of birth in the DD/MM/YYYY format\n";
	cin >> bDay >> bMonth >> bYear;

	while (bDay < 0 || bDay > 31 || bMonth < 0 || bMonth > 12 || bYear < 0)
	{
		cout << "Invalid date. Please try again\n";
		cout << "Enter date of birth in the DD/MM/YYYY format\n";
		cin >> bDay >> bMonth >> bYear;
	}

	cout << "Enter current date in the DD/MM/YYYY format\n";
	cin >> cDay >> cMonth >> cYear;

	while (cDay < 0 || cDay > 31 || cMonth < 0 || cMonth > 12 || cYear < 0)
	{
		cout << "Invalid date. Please try again\n";
		cout << "Enter current date in the DD/MM/YYYY format\n";
		cin >> cDay >> cMonth >> cYear;
	}

	if (cDay < bDay)				
	{
		if (cMonth == 1 || cMonth == 3 || cMonth == 5 || cMonth == 7 || cMonth == 8 || cMonth == 10 || cMonth == 12)			
		{
			cDay = cDay + 31;
			cMonth = cMonth - 1;
		}
		else if (cMonth == 2 || cMonth == 4 || cMonth == 6 || cMonth == 9 || cMonth == 11)			
		{
			cDay = cDay + 30;
			cMonth = cMonth - 1;
		}
		else						
		{
			cDay = cDay + 28;
			cMonth = cMonth - 1;
		}
	}

	if (cMonth < bMonth)			
	{
		cMonth = cMonth + 12;
		cYear = cYear - 1;
	}

	ageday = cDay - bDay;					
	agemonth = cMonth - bMonth;
	ageyear = cYear - bYear;

	cout << "The age is " << ageyear << " years " << agemonth << " months and " << ageday << " days\n";

	system("pause");
	return 0;
}


