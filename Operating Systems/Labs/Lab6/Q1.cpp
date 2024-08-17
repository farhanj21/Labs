#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
using namespace std;

void Q1(int id) {
    cout << "Thread " << id << " ID: " << this_thread::get_id() << ", Process ID: " << getpid() << "\n";
}

int main() {
    int N;
    cout << "Enter number of threads: ";
    cin >> N;
    
    vector<thread> threads;
    for (int i = 0; i < N; ++i) {
        threads.push_back(thread(Q1, i));
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
    
    return 0;
}
