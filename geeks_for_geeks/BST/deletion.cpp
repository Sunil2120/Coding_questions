#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* newNode(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* root,int key)
{
	Node* temp = newNode(key);
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	Node* cur = root;
	Node* prev = NULL;
	while(cur!=NULL)
	{
		prev = cur;
		if(key <= cur->data)
		{
			cur=cur->left;
		}
		else
		{
			cur=cur->right;
		}
	}
	if(key <= prev->data)
	{
		prev->left = temp;
	}
	else
	{
		prev->right = temp;
	}
	return root;
}
Node* search(Node* root,int key)
{
	if(root==NULL)
	{
		return root;
	}
	if(root->data == key)
	{
		return root;
	}
	if(key < root->data)
	{
		return search(root->left,key);
	}
	return search(root->right,key);
}

Node* getMinValue(Node* root)
{
	Node* cur = root;
	while(cur!=NULL && cur->left!=NULL)
	{
		cur=cur->left;
	}
	return cur;
}

Node* delete_node(Node* root,int key)
{
	if(root==NULL)
	{
		return root;
	}
	if(key < root->data)
	{
		root->left = delete_node(root->left,key);
	}
	else if(key > root->data)
	{
		root->right = delete_node(root->right,key);
	}
	else
	{
		// cur root is the node need to be deleted
		// root with only one child
		if(root->left==NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		if(root->right==NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}
		// root with two children
		Node* min_node = getMinValue(root->right);
		// get the inorder successor which is nothing but the min value in right subtree
		root->data = min_node->data;
		root->right = delete_node(root->right,min_node->data);
	}
	return root;
}

void inorder(Node* root)
{
	if(root)
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
	Node* root = NULL;
	while(n--)
	{
		int data;
		cin >> data;
		root = insert(root,data);
	}
	inorder(root);
	cout << endl;
	cout << search(root,5) << endl;
	cout << search(root,10) << endl;
	root = delete_node(root,10);
	root = delete_node(root,20);
	inorder(root);
	return 0;
}