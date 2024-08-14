#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include "bits-stdc++.h"
using namespace std;


map<char, string> codes;
map<char, int> frequency;

class  Node
{
public:
    char data;
    int frequency;
    Node* right;
    Node* Left;

    Node()
    {
        data = '?';
        frequency = 0;
        right = NULL;
        Left = NULL;
    }

    Node(char in, int f)
    {
        frequency = f;
        data = in;
        right = NULL;
        Left = NULL;
    }
};

struct compare
{
    bool operator()(Node* left, Node* right)
    {
        return (left->frequency > right->frequency);
    }
};

void PrintGlossary(Node* root, string str)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data != '$')
    {
        cout << root->data << " : " << str << "\n";
    }
    PrintGlossary(root->Left, str + "0");
    PrintGlossary(root->right, str + "1");
}

void StoringCode(Node* root, string str)
{

    if (root == NULL)
    {
        return;
    }
    if (root->data != '$')
    {
        codes[root->data] = str;
    }
    StoringCode(root->Left, str + "0");
    StoringCode(root->right, str + "1");
}

priority_queue<Node*, vector<Node*>, compare> minHeap;

void HuffmanCodes(int size)
{
    Node* right, * left, * top;


    for (map<char, int>::iterator itr = frequency.begin(); itr != frequency.end(); itr++)
    {
        minHeap.push(new Node(itr->first, itr->second));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->frequency + right->frequency);
        top->Left = left;
        top->right = right;
        minHeap.push(top);
    }

    StoringCode(minHeap.top(), "");
}

void CalcualteFrrquency(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
    {
        frequency[str[i]]++;
    }
}

string HuffmanDecoder(Node* root, string str)
{

    string ans = "";
    Node* current = root;

    for (int i = 0; i < str.size(); i++)
    {
        if (current == NULL)
        {
            break;
        }

        if (str[i] == '0')
        {
            current = current->right;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == NULL)
    {
        current = root;
    }

    if (current != NULL && current->Left == NULL && current->right == NULL)
    {
        ans += current->data;
        current = root;
    }

    return ans + '\0';
}

int main()
{
    string str, line, encodedstring, decodedstring;

    ifstream myfile("q2lab10.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            str = line;
        }
    }

    CalcualteFrrquency(str, str.length());
    HuffmanCodes(str.length());

    cout << "Frequency of Each Character in Huffman:\n";

    for (auto itr = codes.begin(); itr != codes.end(); itr++)
    {
        cout << itr->first << " = " << itr->second << "\n";
    }

    for (auto i : str)
    {
        encodedstring = encodedstring + codes[i];
    }
    cout << "\nEncoded Data:" << encodedstring << "\n";

    decodedstring = HuffmanDecoder(minHeap.top(), encodedstring);

    system("pause");
    return 0;
}