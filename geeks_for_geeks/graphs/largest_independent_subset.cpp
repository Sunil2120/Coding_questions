#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	int dp=0;
	struct node* left=NULL;
	struct node* right=NULL;
};
typedef struct node node;

node* newnode(int key)
{
	node* temp = new node();
	temp->val = key;
	return temp;
}

// here to avoid overlapping subproblems we will add another member to struct dp
// which stores the value for a particular node
// if that node is encounter again we will just return the value
// time O(n) n=>number of nodes.
int solve(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->dp!=0)
	{
		return root->dp;
	}
	// let's take root as a part of set
	int temp = 1;
	if(root->left!=NULL)
	{
		temp+=solve(root->left->left);
		temp+=solve(root->left->right);
	}
	if(root->right!=NULL)
	{
		temp+=solve(root->right->right);
		temp+=solve(root->right->left);
	}
	int temp2 = 0;
	// we won't include root 
	temp2+=solve(root->left)+solve(root->right);
	root->dp =  max(temp,temp2);
	return root->dp;
}

int main()
{
	node* root=NULL;
	root=newnode(10);
	root->left =newnode(20);
	root->right=newnode(30);
	root->left->left = newnode(40);
	root->left->right = newnode(50);
	root->right->right=newnode(60);
	root->left->right->left = newnode(70);
	root->left->right->right=newnode(80);
	cout << solve(root) << endl;
	return 0;

}