#include <iostream>  
using namespace std;  

const int rows = 2;
const int columns = 3;

template <class T>
class Matrix
{
	private:
		T arr[rows][columns];
		int r,c;
public:
Matrix() 
{   
	r = rows;   
	c = columns;   
	for (int i=0; i< r; i++) 
	{     
		for(int j=0; j< c; j++)       
		{         
			arr[i][j] = '\0';       
		}   
	} 
}     

printMatrix() 
{    
	for (int i=0; i< r; i++)    
		{       
			for(int j=0; j< c; j++)       
			{ 	 
				cout << arr[i][j] << "   ";       
			}       
			cout << "\n";    
		} 
}  

setMatrix(T tempArr[][columns]) 
{    
	for (int i=0; i< r; i++)    
	{       
		for(int j=0; j< c; j++)       
			{ 	
			 	arr[i][j] = tempArr[i][j];       
			}    
	} 
}  

addMatrix(T tempArr[][columns]) 
{    
	for (int i=0; i< r; i++)    
	{       
		for(int j=0; j< c; j++)       
		{ 	 
			arr[i][j] = arr[i][j] + tempArr[i][j];       
		}    
	} 
}  
addMatrix(Matrix<T> otherMatrix) 
{    
	addMatrix(otherMatrix.arr); 
}  

};

int main()
{
	int arr1[rows][columns] = { 	  {5,3,2}, 	  {7,1,3}        };     
	int arr2[rows][columns] = { 	  {6,5,4}, 	  {5,6,4}        };     
	Matrix<int> M;                
	
	M.setMatrix(arr1);     
	cout << "First matrix after being set and printed\n"; 
	M.printMatrix();     
	 
	M.addMatrix(arr2);     
	cout << "\nMatrix after being incremented by second array\n";      
	M.printMatrix(); 
	
	system("pause");
	return 0; 

}
