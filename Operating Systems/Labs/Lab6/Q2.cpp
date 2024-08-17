#include <iostream>
#include <thread>
using namespace std;


void summation(int N) {
    int sum = 0;
    for (int i = 0; i <= N; ++i) {
        sum = sum + i;
    }
    cout << "Sum from 0 to " << N << " is: " << sum << "\n";
}

int main() 
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    thread sum_thread(summation, N);
    sum_thread.join();
    
    return 0;
}
