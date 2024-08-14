#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
		int size, top;
		T* St;
public:
	Stack(int n)		
	{
		size = n;
		top = -1;
		St = new T[size];
	}

	~Stack()
	{
		delete [] St;
		top = -1;
		size = 0;
	}

	int push(const T& data)
	{
		if(isFull())
		{
			cout << "Stack is full cannot enter more\n";
			return 0;
		}
		St[++top] = data;
		return 1;
	}		

	int pop(T& data)
	{
		if(isEmpty())
		{
			cout << "Stack has no data to pop\n";
			return 0;
		}
		data = St[top--];
		return 1;
	}

	int isEmpty()
	{
		return (top==-1);
	}
	
	int isFull()
	{
		return (top == size-1);
	}

	void peek()
	{
		if(isEmpty())
		{
			cout << "Stack is empty\n";
			return;
		}
		cout << "Peeked element is " << St[top] << "\n";
	}
};

int main()
{
	Stack<int> s(10);
	int value;
	
	s.push(1);
	s.push(2);
	s.push(3);
	
	if(s.isEmpty())
	{
		cout << "Stack is empty\n";
	}
	else
	{
		cout << "Stack is not empty\n";
	}

	
	s.peek();
	
	s.pop(value);
	cout << "Popped element is " << value;
	
	cout << "\nAfter popping\n";
	s.peek();
	
	system("pause");
	return 0;
}
