#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/

//Flatten BST to sorted list | Increasing order

//Given a binary search tree, the task is to flatten it to a sorted list. Precisely, the value of each node must be lesser than the values of all the nodes at its right, and its left node must be NULL after flattening. We must do it in O(H) extra space where ‘H’ is the height of BST.




// Approach: A simple approach will be to recreate the BST from its in-order traversal. This will take O(N) extra space were N is the number of node in BST.
// To improve upon that, we will simulate in order traversal of a binary tree as follows:

// Create a dummy node.
// Create a variable called ‘prev’ and make it point to the dummy node.
// Perform in-order traversal and at each step.
// Set prev -> right = curr
// Set prev -> left = NULL
// Set prev = curr

// This will improve the space complexity to O(H) in worst case as in-order traversal takes O(H) extra space.
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

void inorder(Node* root,Node*& prev)
{
	if(root!=NULL)
	{
		inorder(root->left,prev);
		prev->left = NULL;
		prev->right = root;
		prev = root;
		inorder(root->right,prev);
	}
}

void printlist(Node* root)
{
	Node* cur = root;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
		cur = cur->right;
	}
	cout << endl;
	return ;
}

Node* flatten(Node* root)
{
	Node* temp = newNode(-1);//dummy node
	Node* prev = temp;
	// we need sorted list so we will call inorder
	inorder(root,prev);
	//last node
	prev->left  = NULL;
	prev->right = NULL;
	root = temp->right;
	// deleting dummy node at the start
	delete(temp);
	return root;

}

int main()
{
	Node* root = newNode(5); 
    root->left = newNode(3); 
    root->right = newNode(7); 
    root->left->left = newNode(2); 
    root->left->right = newNode(4); 
    root->right->left = newNode(6); 
    root->right->right = newNode(8);

    printlist(flatten(root));
	return 0;
}