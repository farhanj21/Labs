#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main(int agrc,char* agrv[])
{
  
  cout<<"Fibonacci\n";
 
    int n = atoi(agrv[0]) ;
    cout << "Enter the value of n: ";
    cin >> n;

    int f = 0, s = 1, next;

    cout << "Fibonacci Series up to " << n << " terms: ";

    for (int i = 0; i < n; i++) 
    {
        if (i <= 1)
            next = i;
        else 
        {
            next = f + s;
            f = s;
            s = next;
        }
        cout << next << " ";
    }
	
	system("pause");
  return 0;

}
