#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
	Complex C1;
	Complex C2(5,6);
	Complex C3;

	cout << "Input a complex number\n";
	C3.setvalue();                                                                                                                                                                                                                                                                                                                ;

	cout <<  C1 << C2 << C3;

	if (C1 == C2)
		cout << "C1==C2\n";
	else
		cout << "C1 != C2\n";
	if (C1 != C3)
		cout << "C1 != C3\n";
	else
		cout << "C1 == C3\n";

	Complex C4 = C2 - C3;
	cout << C4;


	system("pause");
	return 0;
}

