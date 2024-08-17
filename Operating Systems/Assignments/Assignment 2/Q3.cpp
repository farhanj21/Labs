#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <map>
#include <cstring>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <fcntl.h>
using namespace std;

const int MAX_WORD_LENGTH = 100;

void processSegment(const char* segment, map<string, int>& wordCount) {
    istringstream iss(segment);
    string word;
   
    while (iss >> word) 
    {
        for (char& c : word) {
            if (!isalpha(c)) {
                word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
                break;
            }
        }
       
        if (!word.empty()) {
            wordCount[word]++;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <num_segments>\n";
        return 1;
    }

    const char* inputFileName = argv[1];
    int numSegments = stoi(argv[2]);

    int inputFileDescriptor = open(inputFileName, O_RDONLY);
    if (inputFileDescriptor == -1) {
        cerr << "Failed to open file\n";
        return 1;
    }

    off_t fileSize = lseek(inputFileDescriptor, 0, SEEK_END);
    off_t segmentSize = fileSize / numSegments;

    vector<thread> threads;
    vector<map<string, int>> segmentWordCounts(numSegments);

    for (int i = 0; i < numSegments; i++) {
        char* segmentBuffer = new char[segmentSize];
        lseek(inputFileDescriptor, i * segmentSize, SEEK_SET);
        ssize_t bytesRead = read(inputFileDescriptor, segmentBuffer, segmentSize);
       
        if (bytesRead > 0) {
            threads.emplace_back([segmentBuffer, &segmentWordCounts, i]() {
                processSegment(segmentBuffer, segmentWordCounts[i]);
                delete[] segmentBuffer;
            });
        }
    }

    for (thread& t : threads) {
        t.join();
    }

    map<string, int> wordCount;
    for (const map<string, int>& segment : segmentWordCounts) {
        for (const auto& pair : segment) {
            wordCount[pair.first] += pair.second;
        }
    }

    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    close(inputFileDescriptor);

    return 0;
}


