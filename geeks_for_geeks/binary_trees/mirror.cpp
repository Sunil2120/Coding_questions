#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node Node;

Node* create_node(int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void mirror(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirror(root->left);
	mirror(root->right);

	return ;
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
	Node* root = NULL;
	root = create_node(5);
	root->left = create_node(6);
	root->right = create_node(3);
	root->right->left = create_node(4);
	root->right->right = create_node(2);
	inorder(root);
	cout << endl;
	mirror(root);
	inorder(root);
	cout << endl;
	return 0;
}