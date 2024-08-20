#include <iostream>
using namespace std;

int main()
{
	int rollno[5], marks[5], aggregate[5];
	int highestmarks = 0, highestaggregate=0;

	for (int c = 1; c < 6; c++)
	{
		cout << "\nPlease enter the roll number of student no. " << c << "\n";
		cin >> rollno[c];
		cout << "\nPlease enter the marks of Roll Number #" << rollno[c] << " for all 5 subjects\n";

		for (int i = 1; i < 6; i++)
		{
			cin >> marks[i];
			aggregate[c] = aggregate[c] + marks[i];
		}

		if (aggregate[c] > highestmarks)
		{
			highestmarks = aggregate[c];
			highestaggregate = rollno[c];
		}
	}

	cout << "\nStudent Number #" << highestaggregate << " has the highest aggregate marks which is " << highestmarks << "\n";

}