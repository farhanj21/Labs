#include <iostream>
using namespace std;

class Node
{
    public:
    string roomType, filled;
    int capacity, guests;
    Node* next;

    public:
    Node()
	{
        roomType="\0";
        capacity=0;
        guests=0;
        filled="\0";
        next=NULL;
    }
};

class SCL
{
    Node* head;
    Node* tail;
    public:
    SCL()
	{
     head=NULL;
     tail=NULL;
    }
    void add(string type,int limit, int totalguests,string fill)
	{
   		Node* node=new Node;
   		node->roomType=type;
   		node->capacity=limit;
   		node->guests=totalguests;
   		node->filled=fill;
   		if(head==NULL)
		{
   			head=node;
    		tail=node;
   		}
   		else
   		{
    		tail->next=node;
    		node->next=head;
    		tail=node;
   		}
    }

    void print()
	{
        Node* temp=head;
        int count=1;
        do
		{
     		cout<<"Room number "<< count++ <<"\t";
    		cout<<"Room Type: "<<temp->roomType<<"\t";
    		cout<<"Capacity: "<<temp->capacity<<"\t";
    		cout<<"Guests: "<<temp->guests<<"\t";
    		cout<<"Filled: "<<temp->filled<<"\n\n";
   			temp=temp->next;
   			
        }
		while(temp!=head);
		
    }

    void accomodate(int n)
	{
        Node* temp=head;
        int currentCapacity;
        if(n>10)
		{
                cout<<"Room capacity reached\n";
                return;
        }
        do
		{
            if(temp->filled=="Yes")
			{
                temp=temp->next;
            }
            if(n<=temp->capacity)
			{
                currentCapacity=(temp->capacity)-(temp->guests);
                if(n>currentCapacity)
				{
                    temp=temp->next;
                }   
                else
				{
					cout << "\n";
                    cout<<temp->roomType<<"\n";
                    temp->guests+=n;
                    cout<<"Capacity: "<<temp->capacity<<"\n";
                    cout<<"Guests: "<<temp->guests<<"\n";
                   if(currentCapacity==0)
				   {
                    temp->filled="Yes";
                   }
                   else{
                    temp->filled="No";
                   }
                   cout<<"Would it be full: "<<temp->filled<<"\n";
                }
            }
            temp=temp->next;

        }
		while(temp!=head);
    }
    

        
};
    

int main()
{
    SCL l1;
    l1.add("Single",1,0,"No");
    l1.add("Triplet",3,1,"No");
    l1.add("Single",1,1,"Yes");
    l1.add("Quad",4,2,"No");
    l1.add("Suite",10,4,"No");
    l1.add("Family",6,6,"Yes");
    l1.add("Family",6,3,"No");
    l1.print();
    
    cout << "ACCOMODATION STARTS:\n\n";
    
    cout << "For 2 guests:";
    l1.accomodate(2);
    cout << "\n\nFor 1 guest:";
    l1.accomodate(1);
 
	
	system("pause");
	return 0;
}
