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
public:
	LL() 
	{
		head = NULL;
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
	Node<T>* head;
	
	Stack() 
	{
		head = NULL;
	}

	void push(T val)
	{
		Node<T>* n = new Node<T>;
		n->data = val;
		if (head == NULL) 
		{
			head = n;
			return;
		}
		else 
		{
			Node<T>* temp = head;
			head = n;
			n->next = temp;
		}
	}
	
	bool Pop(T& newval) 
	{
		Node<T>* temp = new Node<T>;
		if (head == NULL) 
		{
			return false;
		}
		else 
		{
			temp = head;
			newval = head->data;
			head = head->next;
			delete temp;
			return true;
		}
	}

	bool IsEmpty() 
	{
		if (head == NULL) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	T peek()
	{
		return head->data;
	}
	
	bool Top(T& val) 
	{
		if (head == NULL) 
		{
			return false;
		}
		else 
		{
			val = head->data;
			return true;
		}
	}
	
	int size()const
    {
        Node<T>* temp = head;
        int size = 0;
        while(temp!=NULL)
        {
        	size++;
        	temp=temp->next;
		}
        return size;
    }
    
   void removeAll(const T& character)
	{
		if (head == NULL)
		{
			return;
		}
		
		Node<T>* temp = head;
		while (temp != NULL)
		{
			if (temp == head)
			{
				if (temp->data == character)
				{
					temp = temp->next;
					head = NULL;
					head = temp;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (temp->data == character)
			{
				Node<T>* temp2 = head;
				while (temp2->next != temp)
				{
					temp2 = temp2->next;
				}
				temp2->next = temp->next;
				temp = NULL;
				temp = temp2->next;

			}
			else
			{
				temp = temp->next;
			}
		}
	}
	
	void removeAdjacent(const T& character)
	{
		if (head == NULL || head->next == NULL || head->next->next == NULL)
		{
			return;
		}
		Node<T>* temp = head;
		while (temp != NULL)
		{
			if (temp->next == NULL ||temp->next->next == NULL)
			{
				return;
			}
			if (temp->data == temp->next->data && temp->next->data == temp->next->next->data && temp->data == character)
			{
				if (temp == head)
				{
					for (int i = 0;i < 3;i++)
					{
						head = temp->next;
						temp = NULL;
						temp = head;
					}
				}
				else
				{
					Node<T>* temp2 = head;
					while (temp2->next != temp)
					{
						temp2 = temp2->next;
					}
					for (int i = 0;i < 3;i++)
					{
						temp2->next = temp->next;
						temp = NULL;
						temp = temp2->next;
					}
				}
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	void deleteMiddle()
	{
	    int length=size();
	    length=length/2;
	    Node<T>* prev=NULL;
	    Node<T>* temp=head;
	    for(int i=0; i!=length ; i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=prev->next->next;
	}
	void print() 
	{
		Node<T>* temp = new Node<T>;
			temp = head;
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
	
	int size = st.size();
	cout << "Size of stack is " << size << "\n";

	int top = 0;
	cout << "Top: ";
	st.Top(top);
	cout << top << "\n";
	

	cout << "Peek: " << st.peek() << "\n";

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
	cout << "\n\n";
	
	cout << "Exercise 2a\n";
	Stack<char> s1;
	s1.push('v');
	s1.push('b');
	s1.push('r');
	s1.push('f');
	s1.push('b');
	s1.push('r');
	s1.push('b');
	s1.print();	
	s1.removeAll('r');
	cout << "\nAfter removing all Rs: ";
	s1.print();	
	
	cout << "\n\nExercise 2b\n";
	Stack<char> s2;
	s2.push('a');
	s2.push('a');
	s2.push('a');
	s2.push('b');
	s2.push('x');
	s2.push('x');
	s2.push('b');
	s2.print();
	s2.removeAdjacent('a');
	cout << "\nAfter removing adjacent As: ";
	s2.print();	
	
	cout << "\n\nExercise 3\n";
	Stack<int>s3;
	s3.push(1);
	s3.push(2);
	s3.push(3);
	s3.push(4);
	s3.push(5);
	s3.print();
	s3.deleteMiddle();
	cout << "\nAfter deleting middle: ";
	s3.print();
	cout << "\n";	
	
	system("pause");
	return 0;
}
