#include<bits/stdc++.h>
using namespace std;


struct node{

	int data;
	struct node* left=NULL;
	struct node* right = NULL;
};
typedef struct node node;


node* getnode(int value)
{
	node* temp = new node();
	temp->data = value;
	return temp;
}


int solve(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int count = 0;
	count = max(count,solve(root->left));
	count = max(count,solve(root->right));
	cout << root->data << " " << count+1 << endl;
	return count+1;
}


int main()
{
	node* root = NULL;
	root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->right->right=getnode(5);
	cout << solve(root) << endl;
	return 0;
}