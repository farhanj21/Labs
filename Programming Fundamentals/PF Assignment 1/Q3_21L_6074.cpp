#include <iostream>
using namespace std;


int main()
{
	int r1, r2, r3, r4, r5;
	int r1mrk1, r1mrk2, r1mrk3, r1mrk4, r1mrk5;
	int r2mrk1, r2mrk2, r2mrk3, r2mrk4, r2mrk5;
	int r3mrk1, r3mrk2, r3mrk3, r3mrk4, r3mrk5;
	int r4mrk1, r4mrk2, r4mrk3, r4mrk4, r4mrk5;
	int r5mrk1, r5mrk2, r5mrk3, r5mrk4, r5mrk5;
	int aggR1, aggR2, aggR3, aggR4, aggR5;

	cout << "Enter roll number of 1st Student:\n";
	cin >> r1;
	cout << "\nEnter the marks of Roll Number #" << r1 << " for all 5 subjects\n";
	cin >> r1mrk1 >> r1mrk2 >> r1mrk3 >> r1mrk4 >> r1mrk5;

	cout << "\nEnter roll number of 2nd student:\n";
	cin >> r2;
	cout << "\nEnter the marks of Roll Number #" << r2 << " for all 5 subjects\n";
	cin >> r2mrk1 >> r2mrk2 >> r2mrk3 >> r2mrk4 >> r2mrk5;

	cout << "\nEnter roll number of 3rd student:\n";
	cin >> r3;
	cout << "\nEnter the marks of Roll Number #" << r3 << " for all 5 subjects\n";
	cin >> r3mrk1 >> r3mrk2 >> r3mrk3 >> r3mrk4 >> r3mrk5;

	cout << "\nEnter roll number of 4th student:\n";
	cin >> r4;
	cout << "\nEnter the marks of Roll Number #" << r4 << " for all 5 subjects\n";
	cin >> r4mrk1 >> r4mrk2 >> r4mrk3 >> r4mrk4 >> r4mrk5;

	cout << "\nEnter roll number of 5th student:\n";
	cin >> r5;
	cout << "\nEnter the marks of Roll Number #" << r5 << " for all 5 subjects\n\n";
	cin >> r5mrk1 >> r5mrk2 >> r5mrk3 >> r5mrk4 >> r5mrk5;

	aggR1 = r1mrk1 + r1mrk2 + r1mrk3 + r1mrk4 + r1mrk5;
	aggR2 = r2mrk1 + r2mrk2 + r2mrk3 + r2mrk4 + r2mrk5;
	aggR3 = r3mrk1 + r3mrk2 + r3mrk3 + r3mrk4 + r3mrk5;
	aggR4 = r4mrk1 + r4mrk2 + r4mrk3 + r4mrk4 + r4mrk5;
	aggR5 = r5mrk1 + r5mrk2 + r5mrk3 + r5mrk4 + r5mrk5;

	if (aggR1 > aggR2 && aggR1 > aggR3 && aggR1 > aggR4 && aggR1 > aggR5)
		cout << r1 << " has highest Aggregate of " << aggR1 << "\n";
	else if (aggR2 > aggR1 && aggR2 > aggR3 && aggR2 > aggR4 && aggR2 > aggR5)
		cout << r2 << " has highest Aggregate of " << aggR2 << "\n";
	else if (aggR3 > aggR1 && aggR3 > aggR2 && aggR3 > aggR4 && aggR3 > aggR5)
		cout << r3 << " has highest Aggregate of " << aggR3 << "\n";
	else if (aggR4 > aggR1 && aggR4 > aggR2 && aggR4 > aggR3 && aggR4 > aggR5)
		cout << r4 << " has highest Aggregate of " << aggR4 << "\n";
	else
		cout << r5 << " has highest Aggregate of " << aggR5 << "\n";

	system("pause");
	return 0;
}