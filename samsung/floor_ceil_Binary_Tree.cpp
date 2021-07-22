#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

Node* newnode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


void solve(Node* root,int key,int& floor,int& ceil)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->data == key)
	{
		floor = key;
		ceil = key;
		return ;
	}
	else if(root->data < key)
	{
		floor = max(floor,root->data);

	}
	else
	{
		ceil = min(ceil,root->data);
	}
	solve(root->left,key,floor,ceil);
	solve(root->right,key,floor,ceil);
	return ;
}

int main()
{

	Node* root = NULL;
	root=newnode(8);
	root->left = newnode(4);
	root->right = newnode(12);
	root->left->left = newnode(2);
	root->left->right = newnode(6);
	root->right->left = newnode(10);
	root->right->right = newnode(14);
	int key;
	cin >> key;
	int floor = INT_MIN;
	int ceil = INT_MAX;
	solve(root,key,floor,ceil);
	if(floor == INT_MIN)
	{
		cout << "floor: " << -1 << endl;
	}
	else
	{
		cout << "floor: " << floor << endl;
	}
	if(ceil == INT_MAX)
	{
		cout << "ceil: " << -1 << endl;
	}
	else
	{
		cout << "ceil: " << ceil << endl;
	}
	return 0;
}