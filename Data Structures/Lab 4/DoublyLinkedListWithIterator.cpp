#include <iostream>
using namespace std;
template <typename T>

struct Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* previous;
    Node()
    {
        next = NULL;
        previous = NULL;
    }
};

template <typename T>
class DLL
{
    Node<T>* head;
    Node<T>* tail;
public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    class iterator
    {
        friend class DLL;
    private:
        Node<T>* current;
    public:
        iterator()
        {
            current = NULL;
        }
        iterator(Node<T>* newptr)
        {
            current = newptr;
        }
        T& operator* () const
        {
            return current->data;
        }
        iterator operator++()
        {
            current = current->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            current = current->next;
            return temp;
        }
        bool operator !=(const iterator& itr) const
        {
            return current != itr.current;
        }
        bool operator ==(const iterator& itr) const
        {
            return current == itr.current;
        }
        iterator& operator=(Node<T>* p_Node)
        {
            this->current = p_Node;
            return *this;
        }

    };

    iterator begin() const
    {
        return head;
    }

    iterator end() const
    {
        return tail;
    }

    void insertAtTail(T val)
    {
        Node<T>* node = new Node<T>;
        node->data = val;
        if (head == NULL)
        {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        node->previous = tail;
        node->next = head;
        tail = node;
        head->previous = tail;
    }

    bool isOdd(T value)
    {
        if (value < 10)
        {
            if (value % 2 != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int s = 0;
            while (value != 0)
            {
                s = s + value % 10;
                value = value / 10;
            }
            if (s % 2 != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    void deleteEven()
    {
        Node<T>* temp = head;
        do {
            if (!isOdd(temp->data))
            {
                del(temp->data);
            }
            temp = temp->next;
        } while (temp != head);
    }

    void del(T val)
    {
        Node<T>* temp = head;
        do {
            if (head->data == val)
            {
                Node<T>* temp = head->next;
                temp->previous = tail;
                tail->next = temp;
                delete head;
                head = temp;
            }
            else if (tail->data == val)
            {
                Node<T>* temp = head;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                temp->next = head;
                head->previous = temp;
                delete tail;
                tail = temp;
            }
            if (temp->next->data == val)
            {
                temp->next = temp->next->next;
                temp->next->next->previous = temp;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void print()
    {
        Node<T>* temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    int sum()
    {
        Node<T>* temp = head;
        int total = 0;

        do
        {
            total = total + temp->data;
            temp = temp->next;

        } while (temp != head);
        return total;
    }

    int prod()
    {
        Node<T>* temp = head;
        int  prod = 1;
        do
        {
            prod = prod * temp->data;
            temp = temp->next;

        } while (temp != head);
        return prod;
    }




    int size()const
    {
        Node<T>* temp = head;
        int size = 0;
        if (head != NULL)
        {
            do {
                temp = temp->next;
                size++;
            } while (temp != head);
        }
        return size;
    }

    bool IsEmpty()
    {
        if (tail == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    DLL(const DLL& dll1)
    {
        int headcpy, tailcpy;
        head = dll1.headcpy;
        tail = dll1.tailcpy;
    }

    ~DLL()
    {
        while (head->next != tail)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }

    void moveOccurence(T val)
    {
        Node<T>* temp = head;
        int c = 0;
        do {
            if (temp->data == val)
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                c++;
            }
            temp = temp->next;
        } while (temp != tail);

        for (int i = 0; i < c; i++)
        {
            insertAtTail(val);
        }
    }

};

int main()
{
    DLL<int> l1;
    l1.insertAtTail(9);
    l1.insertAtTail(11);
    l1.insertAtTail(34);
    l1.insertAtTail(6);
    l1.insertAtTail(13);
    l1.insertAtTail(21);

    l1.print();

    cout << "Printing using iterator: ";
    for (auto itr = l1.begin();; itr++)
    {
        cout << *itr << " ";
        if (itr == l1.end())
        {
            break;
        }
    }
    cout << "\n";

    l1.deleteEven();
    cout << "Remaining after deleting even sums: ";
    l1.print();
    cout << "\n";

    int sum = l1.sum();
    cout << "Sum is " << sum << "\n";
    int product = l1.prod();
    cout << "Product is " << product << "\n\n";



    cout << "Size of list is " << l1.size() << "\n\n";

    if (l1.IsEmpty())
    {
        cout << "List is empty\n\n";
    }
    else
    {
        cout << "List is not empty\n\n";
    }


    DLL<int> l2;
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(2);
    l2.insertAtTail(3);
    cout << "Occurence Test:\n";
    l2.print();
    l2.moveOccurence(2);
    cout << "After moving occurence: ";
    l2.print();
    cout << "\n";

    DLL<int> l3;
    l3 = l1;
    cout << "Copy constructor test: ";
    l3.print();
    cout << "\n";

    system("pause");
    return 0;
}