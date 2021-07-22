#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	int count = 0;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node Node;

Node* newnode(int data)
{
	Node* temp = new Node();
	temp->data=data;
	return temp;
}

int insert(Node*& root,int data)
{
	if(root==NULL)
	{
		root = newnode(data);
		return 0;
	}
	if(data > root->data)
	{
		//right and cur root is less than me
		root->count+=1;
		return insert(root->right,data);
	}
	else
	{
		//left and cur root is greater than me and it is left to me
		// all its count(greater than it will so be greater than cur)
		return root->count+1+insert(root->left,data);
	}
	return -1;
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
	for(int i=0;i<n;i++)
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