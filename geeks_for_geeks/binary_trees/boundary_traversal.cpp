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

void leaf_nodes(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->left==NULL && root->right==NULL)
	{
		cout << root->data << " ";
		return ;
	}
	// print all leaf nodes in left
	leaf_nodes(root->left);
	
	// print all leaf nodes in right
	leaf_nodes(root->right);
}

void boundary_left(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->left!=NULL)
	{
		cout << root->data << " ";
		boundary_left(root->left);
	}
	else if(root->right!=NULL)
	{
		cout << root->data << " ";
		boundary_left(root->right);
	}
	// to avoid duplicating we are not considering leaf nodes
	return ;
}

void boundary_right(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->right!=NULL)
	{
		
		boundary_right(root->right);
		cout << root->data << " ";
	}
	else if(root->left!=NULL)
	{
		
		boundary_right(root->left);
		cout << root->data << " ";
	}
	// to avoid duplicating we are not considering leaf nodes
	return ;
}

void boundary(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	cout << root->data << " ";
	//left boundary
	boundary_left(root->left);
	//leaf nodes
	leaf_nodes(root);
	//right boundary
	boundary_right(root->right);
	cout << endl;
	return ;
}

int main()
{
	Node* root = NULL;
	root = create_node(5);
	root->left = create_node(6);
	root->right = create_node(3);
	root->right->left = create_node(4);
	root->right->right = create_node(2);
	boundary(root);
	
	return 0;
}