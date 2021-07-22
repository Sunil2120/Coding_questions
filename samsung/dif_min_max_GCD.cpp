#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;


Node* newnode(int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


void solve(Node* root,int& min_value,int& max_value)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->left!=NULL && root->right!=NULL)
	{
		min_value = min(__gcd(root->left->data,root->right->data),min_value);
		max_value = max(__gcd(root->left->data,root->right->data),max_value);
	}
	solve(root->left,min_value,max_value);
	solve(root->right,min_value,max_value);
	return ;

}
int main()
{
	Node* root=NULL;
	root = newnode(4);
	root->left = newnode(5);
	root->right = newnode(2);
	root->right->left = newnode(3);
	root->right->right = newnode(1);
	root->right->left->left = newnode(6);
	root->right->left->right = newnode(12);
	int min_value = INT_MAX;
	int max_value = INT_MIN;
	solve(root,min_value,max_value);
	if(min_value!=INT_MAX && max_value!=INT_MIN)
	{
		cout << max_value << " " << min_value << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}