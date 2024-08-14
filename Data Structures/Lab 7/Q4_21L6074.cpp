#include<iostream>
#include<stack>
using namespace std;

void insertAt(int item,stack<int>&st)
{
    if (!st.empty())
	{
        int a=st.top();
        st.pop();
        insertAt(item,st);
        st.push(a);
    }
    else
    {
    	st.push(item);
	}
}

void Reverse(stack<int>&st)
{
    if (!st.empty())
	{
        int item=st.top();
        st.pop();
        Reverse(st);
        insertAt(item, st);
    }
}


int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout << "Elements present in stack from top to bottom 1 2 3 4\n";
    Reverse(st);
    
    cout << "Stack after recursive reverse:\n";
    
    while (st.size())
	{
        int top = st.top();
        cout << top << " ";
        st.pop();
    }
    
    cout<<endl;    
    system("pause");
    return 0;
}
