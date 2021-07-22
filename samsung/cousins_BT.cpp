#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* left=NULL;
	struct node* right = NULL;
};
typedef struct node Node;


Node* newnode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}

Node* getchild(Node* root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data == key)
	{
		return root;
	}
	Node* temp = getchild(root->left,key);
	if(temp != NULL)
	{
		return temp;
	}
	temp = getchild(root->right,key);
	return temp;

}

Node* getparent(Node* root,Node* child)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(child==NULL)
	{
		return NULL;
	}
	if(root->left == child || root->right == child)
	{
		return root;
	}
	Node* temp = getparent(root->left,child);
	if(temp!=NULL)
	{
		return temp;
	}
	return getparent(root->right,child);
}

void solve(Node* root,int key)
{
	if(root==NULL)
	{
		return ;
	}
	Node* child = getchild(root,key);
	if(child==NULL)
	{
		return ;
	}
	Node* parent = getparent(root,child);
	
	Node* grandparent = getparent(root,parent);
	if(parent==NULL || grandparent == NULL)
	{
		cout << 0 << endl;
		return ;
	}
	cout << child->data << " " << parent->data << " " << grandparent->data << endl;
	if(grandparent->left == parent)
	{
		if(grandparent->right!=NULL)
		{
			if(grandparent->right->left!=NULL)
			{
				cout << (grandparent->right->left)->data << " ";
			}
			if(grandparent->right->right!=NULL)
			{
				cout << (grandparent->right->right)->data << endl;
			}
		}
		else
		{
			cout << 0 << endl;
			return ;
		}
	}
	else
	{
		if(grandparent->left!=NULL)
		{
			if(grandparent->left->left!=NULL)
			{
				cout << (grandparent->left->left)->data << " ";
			}
			if(grandparent->left->right!=NULL)
			{
				cout << (grandparent->left->right)->data << endl;
			}
		}
		else
		{
			cout << 0 << endl;
			return ;
		}
	}
	return ;
}

int main()
{
	Node* root = NULL;
	root = newnode(1);
	root->left = newnode(3);
	root->right = newnode(7);
	root->left->left = newnode(6);
	root->left->right = newnode(5);
	root->right->left = newnode(4);
	root->right->right = newnode(13);
	root->left->right->left = newnode(10);
	root->right->left->left = newnode(17);
	root->right->left->right = newnode(15);
	int key;
	cin >> key;
	solve(root,key);
	return 0;


}