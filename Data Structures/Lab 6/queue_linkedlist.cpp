#include <iostream>
using namespace std;

template <typename T>
class node 
{
public:
	T data;
	node<T>* next;

	node() 
	{
		data = 0;
		next = NULL;
	}
	node(const T& item, node<T>* ptr = NULL)
	{
		data = item;
		next = ptr;
	}
};



template <typename T>
class LL 
{
private:
	node<T>* front;
	node<T>* rear;
public:
	LL() 
	{
		front = rear = new node<T>();
	}
	~LL()
	{
		while (front->next != NULL) 
		{
			node<T>* temp = front;
			front = front->next;
			delete temp;
		}
		delete front;
	}

	
};


template <typename T>
class Queue 
{
public:
	node<T>* front;
	node<T>* rear;
	
	Queue() 
	{
		front = NULL;
		rear = NULL;
	}

	void Enqueue(T val)
	{
		node<T>* temp = new node<T>;
		temp->data = val;
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
	}
	bool Dequeue(const T& newval) 
	{
		node<T>* temp = front;
		if (front == NULL) 
		{
			return false;
		}
		else 
		{
			front = front->next;
			front->data = newval;
			return true;
		}
		delete temp;
	}

	bool IsEmpty() 
	{
		if (front == NULL && rear == NULL) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	void display() 
	{
		node<T>* temp = new node<T>;
		if (front == NULL) 
		{
			cout << "Queue is empty \n" << "\n";
		}
		else 
		{
			temp = front;
			while (temp != NULL) 
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << "\n";
		}
	}
};



int main()
{
	Queue<int> obj;
	obj.Enqueue(1);
	obj.Enqueue(2);
	obj.Enqueue(3);
	obj.Enqueue(4);
	
	cout << "Enqueing\n";
	obj.display();
	cout << "\n";
	
	cout << "Dequeue 70: \n";
	obj.Dequeue(70);
	obj.display();
	cout << "\n";
	
	cout << "Is Queue empty\n";
	if(!obj.IsEmpty())
	{
		cout << "It is not empty\n";
	}
	else
	{
		cout << "It is empty\n";
	}
	
	cout << "\n";
	obj.Dequeue(70);
	cout << "Calling dequeue";
	cout << "\n\n";

	obj.display();
	cout << "\n";

	system("pause");
	return 0;
}
