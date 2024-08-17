#include <iostream>
#include <thread>
#include <fstream>
using namespace std;

int* fibonacciGenerator(int N, int& size) {
    if (N <= 0) {
        size = 0;
        return nullptr;
    }

    int* series = new int[N];
    int a = 0, b = 1;
    series[0] = a;

    size = 1;
    while (size < N) {
        series[size] = b;
        int tmp = b;
        b = a + b;
        a = tmp;
        ++size;
    }
    return series;
}

void countEven(int* series, int size, int& count) {
    count = 0;
    for (int i = 0; i < size; ++i) {
        if (series[i] % 2 == 0) {
            ++count;
        }
    }
}

void countOdd(int* series, int size, int& count) {
    count = 0;
    for (int i = 0; i < size; ++i) {
        if (series[i] % 2 != 0) {
            ++count;
        }
    }
}

void sumAndWriteToFile(int* series, int size, int& sum) {
    sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += series[i];
    }
    ofstream file("sum.txt");
    file << sum;
    file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <N>" << endl;
        return 1;
    }
    int N = stoi(argv[1]);

    int* series;
    int size, evenCount, oddCount, sum;

    thread fibonacciThread([&series, &size, N] {
        series = fibonacciGenerator(N, size);
        cout << "ID = " << this_thread::get_id() << ", Series: ";
        for (int i = 0; i < size; ++i) {
            cout << series[i] << " ";
        }
        cout << "\n";
    });
    fibonacciThread.join();

    if (series != nullptr) {
        thread evenThread(countEven, series, size, ref(evenCount));
        evenThread.join();
        cout << "ID = " << this_thread::get_id() << ", Even Numbers: " << evenCount << "\n";

        thread oddThread(countOdd, series, size, ref(oddCount));
        oddThread.join();
        cout << "ID = " << this_thread::get_id() << ", Odd Numbers: " << oddCount << "\n";

        thread sumThread(sumAndWriteToFile, series, size, ref(sum));
        sumThread.join();
        cout << "ID = " << this_thread::get_id() << ", Sum: " << sum << "\n";

        delete[] series;
    }
    return 0;
}

