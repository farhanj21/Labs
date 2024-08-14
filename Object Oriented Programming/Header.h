using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date() 
	{
		day = 1;
		month = 1;
		year = 1926;
	}

	void Print();

	Date(int x, int y, int z)  
	{
		day = x;
		month = y;
		year = z;
	}
	
	~Date() 
		{

		}

	void Input();
	void SetDay(int d);
	void SetMonth(int m);
	void SetYear(int y);
	int GetDay();
	int GetMonth();
	int GetYear();
	int Compare(Date d2);
	void IncrementMonth();




};