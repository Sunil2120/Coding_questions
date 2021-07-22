#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* left=NULL;
	struct node* right=NULL;
	int count = 0;
};
typedef struct node Node;


Node* newnode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}

int insert(Node*& root,int data)
{
	if(root==NULL)
	{
		root = newnode(data);
		return 0;
	}
	if(data > root->data)//root is on right side and all its smaller value are smaller than me
	{
		return root->count + 1 + insert(root->right,data);
	}
	// root is on right side and it is greater than me so i cant do anything and i will increment root left count
	// data <= root->data
	root->count+=1;
	return insert(root->left,data);
}
int main()
{
	int n;
	cin >> n;
	Node* root = NULL;
	int* arr = new int[n];
	int* count = new int[n]();
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		count[i]=insert(root,arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout << count[i] << " ";
	}
	cout << endl;
	return 0;
}