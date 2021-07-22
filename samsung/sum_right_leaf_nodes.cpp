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


int solve(Node* root,Node* prev)
{
	if(root==NULL)
	{
		return 0;
	}
	int sum = 0;
	if(root->left==NULL && root->right==NULL)
	{
		if(prev->left==root && prev->right!=NULL)
		{
			sum+=root->data;
		}
	}
	sum+=solve(root->left,root);
	sum+=solve(root->right,root);
	return sum;
}


int main()
{

	
	Node* root = NULL;
	root = newnode(9);
	root->left = newnode(8);
	root->right = newnode(6);
	root->left->left = newnode(5);
	root->left->right = newnode(2);
	root->right->left = newnode(10);
	root->right->right = newnode(1);  
	cout << solve(root,NULL) << endl;
	return 0;

}