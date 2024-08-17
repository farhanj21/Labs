#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
using namespace std;
mutex mtx; 

void calcAvg(const vector<int>& numbers, double& result) {
    double sum = 0;
    for (int num : numbers) {
        sum = sum + num;
    }
    result = sum / numbers.size();
}

void calcMax(const vector<int>& numbers, int& result) {
    int max=-999;
    for(int i =0;i<numbers.size();++i)
    	{
			if(numbers[i] > max)
		{
			max = numbers[i];
		}
    	}
    result = max;
    }

void calcMin(const vector<int>& numbers, int& result) {
     int min = 9999;
    for(int i =0;i<numbers.size();++i)
    {
	if(numbers[i] < min)
	{
		min = numbers[i];
	}
    }
    result = min;
    }


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " num1 num2 num3 to N\n";
        return 1;
    }

    vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        numbers.push_back(stoi(argv[i]));
    }

    double avg = 0;
    int max = 0;
    int min = 0;

    thread avgThread(calcAvg, ref(numbers), ref(avg));
    thread maxThread(calcMax, ref(numbers), ref(max));
    thread minThread(calcMin, ref(numbers), ref(min));

    avgThread.join();
    maxThread.join();
    minThread.join();

    cout << "Average: " << avg << "\n";
    cout << "Maximum: " << max << "\n";
    cout << "Minimum: " << min << "\n";

    return 0;
}

	

