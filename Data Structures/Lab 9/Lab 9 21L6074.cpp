#include <iostream>
using namespace std;
template <typename T>

class minHeap
{
    T* heapArr;
    int heapsize;
    int capacity;
    
	public:
		
	minHeap()
	{
		heapsize = 0;
		capacity = 0;
		heapArr = '\0';
	}
		
    minHeap(T* arr,int N)
	{
        int x=0,y=0;
        heapArr=new T[N];
        capacity=N;
        heapsize=0;
        
        T* temp=new T [N];
        for(int i=0;i<N;i++)
		{
            temp[x++]=arr[i];
        }
       
        
        for(int i=0;i<N;i++)
		{
            heapArr[y++]=temp[i];
        }
        for(int i=0;i<N;i++)
		{
            insert(heapArr[i]);
        }
    }
    
    void print()
	{
        for(int i=0;i<heapsize;i++)
		{
            cout<<heapArr[i]<<" ";
        }
        cout<<"\n";
    }
    
    bool isempty()
	{
        if(heapsize==0)
		{
            return true;
        }
        else
		{
            return false;
        }
    }
   
    int parent(int i)
	{
        return (i-1)/2;
    }
    int left(int i)
	{
        return (i*2)+1;
    }
    int right(int i)
	{
        return (i*2)+2;
    }
    
     void swap(int& x, int& y)
	{
        int temp=x;
        x=y;
        y=temp;
    }
    
    void insert(int k)
	{
        if(heapsize==capacity)
		{
            return;
        }
        heapsize++;
        int i=heapsize-1;
        heapArr[i]=k;
        while(i!=0&&heapArr[parent(i)]>heapArr[i])
		{
            swap(heapArr[parent(i)],heapArr[i]);
            i=parent(i);
        }
    }

    void heapify(int i)
	{
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l<heapsize&&heapArr[l]<heapArr[i])
		{
            largest=l;
        }
        if(r<heapsize&&heapArr[r]<heapArr[largest])
		{
            largest=r;
        }
        if(largest!=i)
		{
            swap(heapArr[i],heapArr[largest]);
            heapify(largest);
        }
    }
    
    int getMin()
	{
        if(heapsize==0)
		{
            return 0;
        }
        else if(heapsize==1)
		{
            heapsize--;
            return heapArr[0];
        }
        int root=heapArr[0];
        heapArr[0]=heapArr[heapsize-1];
        heapsize--;
        heapify(0);
        return root;
    }
    void del(int i, int min)
	{
        heapArr[i]=min;
        while(i!=0&&heapArr[parent(i)]>heapArr[i])
		{
            swap(heapArr[parent(i)],heapArr[i]);
            i=parent(i);
        }
    }
    void deleteAll(T key)
	{
        int value=0;
        for(int i=0;i<heapsize;i++)
		{
            if(heapArr[i]==key)
			{
                value=i;
                break;
            }
        }
        del(value,INT_MIN);
        getMin();
    }
};

template <typename T>
void HeapSort(T* arr,int size,int sortingOrder)
{
    minHeap <int> heap1(arr,size);
    T* temp=new T [size];
    for(int i=0;i<size;i++)
	{
        temp[i]=heap1.getMin();
    }
    if(sortingOrder==1){
        for(int i=0;i<size;i++){
        cout<<temp[i]<<" ";
        }
    }
    else if(sortingOrder==0)
	{
        int current=0;
        int next=size-1;
        while(current<next)
		{
            swap(temp[current],temp[next]);
            current++;
            next--;
        }
        for(int i=0;i<size;i++)
		{
        cout<<temp[i]<<" ";
        }
    }
}

int main()
{
    int array[]={10,4,5,30,3,300};
    minHeap <int> obj(array,6);
    cout << "MinHeap has been created and 10,4,5,30,3,300 have been inserted\n";
    
    cout << "1st, 2nd, 3rd Minimum are: ";
    for(int i=0;i<3;i++)
	{
        cout<<obj.getMin()<<" ";
    }
    
    bool flag = obj.isempty();
    if(flag==false)
    {
    	cout << "\nHeap is not empty\n";
	}
	else
	{
		cout << "\nHeap is empty\n";
	}
    
    cout << "Heap after deleting first three miniumum: ";
	obj.print();
	
	obj.deleteAll(300);
	cout << "Heap after deleting 300: ";
	obj.print();
	
	cout << "Heap sort in ascending: ";
    HeapSort(array,6,1);
    cout<<"\nHeap sort in descending: ";
    HeapSort(array,6,0);
    cout << "\n";
    
    system("pause");
    return 0;
    }
