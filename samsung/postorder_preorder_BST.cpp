#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left=NULL;
	struct node* right = NULL;
};
typedef struct node Node;


Node* newnode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	return temp;
}

// preorder
Node* solve(vector<int>& input,int& pos,int key,int min,int max,int size)
{
	if(pos>=size)
	{
		return NULL;
	}
	Node* root = NULL;
	if(key > min && key < max)
	{
		root = newnode(key);
		pos = pos+1;
		if(pos < size)
		{
			root->left = solve(input,pos,input[pos],min,key,size);
		}
		if(pos < size)
		{
			root->right = solve(input,pos,input[pos],key,max,size);
		}
	}
	return root;
}

//postorder
Node* solve2(vector<int>& input,int& pos,int key,int min,int max,int size)
{
	if(pos < 0)
	{
		return NULL;
	}
	Node* root = NULL;
	if(key > min && key < max)
	{
		root = newnode(key);
		pos = pos-1;
		if(pos >= 0)
		{
			root->left = solve2(input,pos,input[pos],min,key,size);
		}
		if(pos >= 0)
		{
			root->left = solve2(input,pos,input[pos],key,max,size);
		}
	}
	return root;

}

void inorder(Node*  root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		cout << root->data << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> input;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		input.push_back(val);
	}
	
	Node* root = NULL;
	int pos = n-1;
	root = solve2(input,pos,input[pos],INT_MIN,INT_MAX,n);
	inorder(root);
	return 0;
}