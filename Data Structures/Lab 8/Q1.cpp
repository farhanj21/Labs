#include <iostream>
#include <stack>
using namespace std;
int count = 1;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	
	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	Node* root;
	
	BST()
	{
		root = NULL;
	}

void insert(int val)
{
        Node* count= new Node;
        count->data=val;
        if(root==NULL){
            root=count;
            return;
        }
        Node*temp=root;
        while(temp!=NULL){
        if(temp->data==count->data){
            return;
        }
        else if(count->data<temp->data&&temp->left==NULL){
            temp->left=count;
        }
        else if(count->data<temp->data){
            temp=temp->left;
        }
        else if(count->data>temp->data&&temp->right==NULL){
            temp->right=count;
        }
        else{
            temp=temp->right;
   }
        }
    }
	void inorderPrint() const
	{
		Node* temp = root;
		stack<Node*> st;
		while (temp != NULL || !st.empty()) 
		{
			if (temp != NULL) 
			{
				st.push(temp);
				temp = temp->left;
			}
			else {
				temp = st.top();
				st.pop();
				cout << temp->data << " ";
				temp = temp->right;
			}
		}
	}
	BST(const BST& rhs)
	{

    root = rhs.root;
    root->left = rhs.root->left;
    root->left = rhs.root->left;


    Node* copy = new Node;
    if (root != NULL)
    {
        copy->data = rhs.root->data;
        copy->left = rhs.root->left;
        copy->right = rhs.root->right;
    }
	}
	
	void levelorderPrint() const
	{

	}
	Node* search(Node*root,int key)
	{
    Node*temp=root;
   if(root==NULL||root->data==key){
    return root;
   }
   if(key>root->data)
   {
    return search(root->right,key);
   }
   else
   {
    return search(root->left,key);
   }
   }
   
int CountNodes(Node*root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
	{
		count++;
		count=CountNodes(root->left);
	}
	if(root->right!=NULL)
	{
		count++;
		count=CountNodes(root->right);
	}
	return count;
}
	
	int leafCount(Node  *node) 
	{
		static int count = 0;
		if (node != NULL)
		{
			leafCount(node->left);
			if ((node->left == NULL) && (node->right == NULL))
			{
				count++;
			}
			leafCount(node->right);
		}
		return count;
	}
	~BST()
	{
		
	}
};




int main()
{
	BST tree;
	tree.insert(1);
	tree.insert(4);
	tree.insert(2);
	tree.insert(3);
	tree.insert(5);
	
	tree.inorderPrint();
	if(tree.search(tree.root,3)!=NULL)
	{
		cout << "\nSearched Node in tree is " << tree.search(tree.root, 3)->data << "\n";
	}
	else
	{
		cout << "\nSearch failed, it does not exist\n";
	}
	
	BST t1 = tree;
	t1.inorderPrint();
	
	cout << "\nTotal nodes in tree are " << tree.CountNodes(tree.root);
	cout << "\nLeaf nodes are " << tree.leafCount(tree.root) << "\n";

	system("pause");
	return 0;
}
