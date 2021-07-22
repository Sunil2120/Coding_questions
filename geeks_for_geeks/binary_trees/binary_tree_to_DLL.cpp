#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n) where n is the number of nodes in given Binary Tree. 
// The solution simply does two traversals of all Binary Tree nodes.
// auxillary space : O(1)
//https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
struct node
{
	int data;
	struct node* left ;
	struct node* right;
};
typedef struct node Node;


Node* newNode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


void leftptr(Node* root,Node*& prev)
{
	if(root!=NULL)
	{
		leftptr(root->left,prev);
		root->left = prev;
		prev = root;
		leftptr(root->right,prev);
	}
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
void print_dll(Node* root)
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

Node* solve(Node* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	Node* prev1 = NULL;
	leftptr(root,prev1);//left pointers are done
	Node* cur = root;
	// we are going to right most node(it is the last node in DLL)
	while(cur!=NULL && cur->right!=NULL)
	{
		cur=cur->right;
	}
	Node* prev = NULL;
	//setting the right pointers
	while(cur!=NULL && cur->left!=NULL)
	{
		prev = cur;
		cur = cur->left;
		cur->right = prev;
	}
	return cur;
}

int main()
{
	Node *root = newNode(10);  
    root->left = newNode(12);  
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);  
  
    cout<<"\n\t\tInorder Tree Traversal\n\n";  
    inorder(root);  
    cout << endl;
    cout << "dll" << endl;
    Node* root2 = solve(root);
    print_dll(root2);
	return 0;
}