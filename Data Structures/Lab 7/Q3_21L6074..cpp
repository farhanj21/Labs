#include <iostream>
using namespace std;
int fibonacci(int num)
{
    if (num <= 1)
    {
    	return num;
	}
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int stringCompare(char const* string1, char const* string2)
{
	char s1 = *string1, s2 = *string2;
	
	if(s1>s2)
	{
		return 1;
	}
	if(s1<s2)
	{
		return -1;
	}
	if(s1=='\0')
	{
		return 0;
	}
	return stringCompare(string1+1,string2+1);
	
}

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
public:
	Node<T>* head;
	
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
	
	Node<T>* reverse(Node<T>* head)
	{
		if (head==NULL || head->next==NULL)
		{
			return head;
		}
		
		Node<T>*rest = reverse(head->next);
		head->next->next = head;
		head->next=NULL;
		
		return rest;
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
	
	int length(Node<T>* head)
	{
		if(head == NULL)
		{
			return 0;
		}
		return 1 + length(head->next);
	}
	
	Node<T>* deleteAll(Node<T>* head)
	{
		if(head==NULL)
		{
			return NULL;
		}
		deleteAll(head->next);
		head=NULL;
		return head;
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
	for(int i=0;i<3;i++)
	{
	char s1[100];
	char s2[100];
	
	cout <<"Enter 2 strings to compare\n";
	cin.getline(s1,100);
	cin.getline(s2,100);
	
	int eq = stringCompare(s1,s2);
	if(eq==0)
	{
		cout << "Strings are equal\n";
	}
	else
	{
		cout << "Strings are not equal\n";
	}
	}
	
	cout << "\nFibonacci Number for n=10 is " << fibonacci(10) << "\n";
	
	LL<int>l1;
	l1.push(10);
	l1.push(9);
	l1.push(7);
	l1.push(5);
	
	cout << "Before recursive\n";
	l1.print();
	
	l1.head = l1.reverse(l1.head);
	
	cout << "\nAfter recursive\n";
	l1.print();
	
	cout << "\nLength of linked list is " << l1.length(l1.head) << "\n";
	
	l1.deleteAll(l1.head);
	cout << "Linked List has been deleted\n";

	system("pause");
	return 0;
}

