#include<iostream>
#include <stack>
using namespace std;

void insertAt(int item,stack<int>&st)
{
    if(st.empty()||item>st.top())
    {
    	st.push(item);
	}
    else
	{
        int top=st.top();
        st.pop();
        insertAt(item,st);
        st.push(top);
    }
}

void sortRecursion(stack<int>&st)
{
    if(!st.empty()){
        int top=st.top();
        st.pop();
        sortRecursion(st);
        insertAt(top,st);
    }
}

int main()
{
    stack<int>st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    
    cout << "Elements present in stack from top to bottom -3 14 18 -5 30\n";
    
    sortRecursion(st);
    
    
    cout<<"After recursion sorting:\n";
    while(!st.empty())
	{
        int top=st.top();
        st.pop();
        cout<<top<<" ";
    }
    
    
    cout << endl;
    system("pause");
    return 0;
}
