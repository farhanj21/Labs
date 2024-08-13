using namespace std;

class Complex
{
	int real;
	int imaginary;
public:
	Complex()
	{
		real = 0;
		imaginary = 0;
	}
	
	Complex(int r, int i);	
	void setvalue()
    {
        cin>>real;
        cin>>imaginary;
    }

	~Complex()
	


};
