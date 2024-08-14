#include<iostream>

using namespace std;

template <typename T>
class Node
{
public:

    T data;
    Node* next;
    Node* previous;

    Node()
    {
        data = 1;
        next = NULL;
        previous = NULL;
    }
    Node(T item)
    {
        data = item;
    }
};

template <typename T>
class LL
{

    Node<T>* head = NULL;
    Node<T>* tail = NULL;

    
public:

    LL()
    {

    }
    void insertAtStart(T const element)
    {
        Node<T>* temp = new Node<T>;
        temp->data = element;
       
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            
            head->previous = temp;
            temp->next = head;
            head = temp;      
            return;
        }
    }
    void insertAtEnd(T const element)
    {
        Node<T>* temp = new Node<T>;
        temp->data = element;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next= temp;
            temp->previous = tail;
            tail = temp;
            return;
        }
    }
    
    void DeleteAtStart()
    {
        Node<T> *temp;

        if (head == NULL)
        {
            head->data = 0;
            return;
        }

        else
        {
            temp = head->next;
            delete[]head;
            head = temp;
            return;
        }
    }
    void DeleteAtEnd()
    {
        Node<T>* temp;

        if (head == NULL)
        {
            head->data = 0;
            return;
        }

        else
        {
            temp = tail->previous;
            delete[]tail;
            tail = temp;
            tail->next = 0;
            return;
        }
    }

    int size()
    {
        Node<T>* temp = head;
        int size = 0;

        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    
    void printF()
    {
        Node<T>* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void printR()
    {
        Node<T>* temp = tail;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->previous;
        }
    }

    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        
        }
        return false;
    }

    void ReturnMiddle ()
    {
        Node<T>* headtemp=head;
        Node<T>* tailtemp=tail;
        while (head != tail || head->next == head->previous)
        {
           // headtemp = headtemp->next;
            //tailtemp = tailtemp->previous;
        }
        cout << "MId  : " << headtemp->data << endl;
    }
};


int main()
{
    LL<int> list;


    /////insert//////////////////////////////////////////
    //list.insertAtStart(1);
    //list.insertAtStart(2);
    //list.insertAtStart(3);
    //list.insertAtStart(4);
    //cout << "------------------------------------\n";
    //list.printF();
    //cout << "------------------------------------\n";
    //list.printR();
    //cout << "------------------------------------\n";
    //list.insertAtEnd(6);
    //list.insertAtEnd(7);
    //list.insertAtEnd(8);
    //list.insertAtEnd(9);
    //cout << "------------------------------------\n";
    //list.printF();
    //cout << "------------------------------------\n";
    //list.printR();
    //cout << "------------------------------------\n";
    //////////////////////////////////////////////////////////////////



    //delete
   /* list.insertAtStart(1);
    list.insertAtStart(2);
    list.insertAtStart(3);
    list.insertAtStart(4);
    cout << "------------------------------------\n";
    list.printF();
    list.DeleteAtStart();
    list.DeleteAtEnd();
    cout << "------------------------------------\n";
    list.printF();
    cout << "------------------------------------\n";*/
    //////////////////////////////////////////////////////////


    //size////////
    list.insertAtStart(1);
    list.insertAtStart(2);
    list.insertAtStart(3);
   
    cout << list.size();
  
    list.printF();
 
    list.ReturnMiddle();
   

    system("pause>0");
}
