#include<bits/stdc++.h>
using namespace std;

struct node{

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

Node* insert(Node* root,int data)
{
	Node* temp = newnode(data);
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	Node* cur = root;
	Node* prev = NULL;
	while(cur!=NULL)
	{
		prev=cur;
		if(data <= cur->data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	if(prev!=NULL)
	{
		if(data <= prev->data)
		{
			prev->left = temp;
		}
		else
		{
			prev->right = temp;
		}
	}
	return root;
}

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);
	}
}

void levelOrder(Node* root)
{
	//cout << "Hello" << endl;
	Node* cur = root;
	queue<Node*> Q;
	if(root==NULL)
	{
		return ;
	}
	Q.push(cur);
	while(!Q.empty())
	{
		Node* temp = Q.front();
		Q.pop();
		cout << temp->data << endl;
		if(temp->left !=NULL)
		{
			Q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			Q.push(temp->right);
		}
	}
	return ;
}

Node* solve(Node* root,int left,int right)
{
	if(root==NULL)
	{
		return root;
	}
	root->left = solve(root->left,left,right);
	root->right = solve(root->right,left,right);
	if(root->data < left)
	{
		if(root->right!=NULL)
		{
			root=root->right;
		}
		else
		{
			root=NULL;
		}
	}
	else if(root->data > right)
	{
		if(root->left!=NULL)
		{
			root=root->left;
		}
		else
		{
			root=NULL;
		}
	}
	return root;
}
int main()
{

	int n;
	cin >> n;
	Node* root = NULL;
	for(int i=0;i<n;i++)
	{
		int value;
		cin >> value;
		root = insert(root,value);
	}
	levelOrder(root);
	int l,r;
	cin >> l >> r;
	root = solve(root,l,r);
	levelOrder(root);
	return 0;

}