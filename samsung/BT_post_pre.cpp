#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left=NULL;
	struct node* right=NULL;
};
typedef struct node Node;



Node* newnode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}

int findIndex(vector<int>& In,int l,int r,int value)
{
	int i;
	for(i=l;i<=r;i++)
	{
		if(In[i]==value)
		{
			return i;
		}
	}
	return 0;
}

// Preorder
Node* solve(vector<int>& In,vector<int>& Pre,int& pos,int l,int r,int size)
{
	if(l > r)
	{
		return NULL;
	}
	if(pos >= size)
	{
		return NULL;
	}
	Node* root = newnode(Pre[pos]);
	pos+=1;
	if(l==r)
	{
		return root;
	}
	int index = findIndex(In,l,r,root->data);
	root->left = solve(In,Pre,pos,l,index-1,size);
	root->right = solve(In,Pre,pos,index+1,r,size);
	return root;
}

//Postorder
Node* solve2(vector<int>& In,vector<int>& Pre,int& pos,int l,int r,int size)
{
	if(l > r)
	{
		return NULL;
	}
	if(pos < 0)
	{
		return NULL;
	}
	Node* root = newnode(Pre[pos]);
	pos-=1;
	if(l==r)
	{
		return root;
	}
	int index = findIndex(In,l,r,root->data);
	root->left = solve(In,Pre,pos,l,index-1,size);
	root->right = solve(In,Pre,pos,index+1,r,size);
	return root;
}

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> In;
	vector<int> Pos;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		In.push_back(val);
	}
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		Pos.push_back(val);
	}
	Node* root = NULL;
	int pos = n-1;
	root = solve2(In,Pos,pos,0,n-1,n);
	inorder(root);
	return 0;
}