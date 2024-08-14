#include <iostream>
using namespace std;

template <typename T>
class Node 
{
public:
	T data;
	Node<T>* next;

	Node() 
	{
		data = 0;
		next = NULL;
	}
	Node(const T& item, Node<T>* ptr = NULL)
	{
		data = item;
		next = ptr;
	}
};

template <typename T>
class LL 
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LL() 
	{
		head = tail = new Node<T>();
	}
	~LL()
	{
		while (head->next != NULL) 
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		delete head;
	}
};


template <typename T>
class Stack 
{
public:
	Node<T>* top;
	
	Stack() 
	{
		top = NULL;
	}

	void push(T val)
	{
		Node<T>* n = new Node<T>;
		n->data = val;
		if (top == NULL) 
		{
			top = n;
			return;
		}
		else 
		{
			Node<T>* temp = top;
			top = n;
			n->next = temp;
		}
	}
	
	bool Pop(T& newval) 
	{
		Node<T>* temp = new Node<T>;
		if (top == NULL) 
		{
			return false;
		}
		else 
		{
			temp = top;
			newval = top->data;
			top = top->next;
			delete temp;
			return true;
		}
	}

	bool IsEmpty() 
	{
		if (top == NULL) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	bool Top(T& val) 
	{
		if (top == NULL) 
		{
			return false;
		}
		else 
		{
			val = top->data;
			return true;
		}
	}
	
	void print() 
	{
		Node<T>* temp = new Node<T>;
			temp = top;
			while (temp != NULL) 
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
	}
};



int main()
{
	Stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
	cout << "After pushing: ";
	st.print();
	cout << "\n";

	int top;
	cout << "Top: " << st.Top(top) << "\n";

	int pop;
	st.Pop(pop);
	cout << "Pop: " << pop << "\n";
	
	cout << "IsEmpty: ";
	if(!st.IsEmpty())
	{
		cout << "False\n";
		
	}
	else
	{
		cout << "True\n";
	}

	cout << "Stack after popping: ";
	st.print();
	cout << "\n";	

	system("pause");
	return 0;
}


