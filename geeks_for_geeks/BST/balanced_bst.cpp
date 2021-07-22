// A balanced bst is a bst whose difference between height of left subtree and height of right subtree
// should not be greater than 1

//https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

// An Efficient Solution can construct balanced BST in O(n) time with minimum possible height. Below are steps.

// Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
// Build a balanced BST from the above created sorted array using the recursive approach discussed here. This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.
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

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

Node* Helper(vector<int>& arr,int left,int right)
{
	if(left > right)
	{
		return NULL;
	}
	int mid = (left+right)/2;
	Node* root = newNode(arr[mid]);
	if(left==right)
	{
		return root;
	}
	root->left = Helper(arr,left,mid-1);
	root->right = Helper(arr,mid+1,right);
	return root;
}

// constructing bst from sorted array problem
Node* solve(vector<int>& arr,int n)
{
	return Helper(arr,0,n-1);
}

void inorder2(Node* root,vector<int>& arr)
{
	if(root!=NULL)
	{
		inorder2(root->left,arr);
		arr.push_back(root->data);
		inorder2(root->right,arr);
	}
}

void preorder(Node* root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	Node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
	vector<int> arr;
	inorder2(root,arr);
	root = solve(arr,arr.size());
	preorder(root);
	cout << endl;
	return 0;
}