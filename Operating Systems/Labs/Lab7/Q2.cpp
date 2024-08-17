#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream input("input.txt"); 
    ofstream output("output.txt"); 


    if (!input.is_open() || !output.is_open()) {
        cout << "Error opening files\n";
        return 1;
    }

    string line;

    while (getline(input, line)) {
        output << line << "\n";
    }

    input.close();
    output.close();

    return 0;
}


