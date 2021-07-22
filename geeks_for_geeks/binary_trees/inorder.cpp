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

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}


// time complexity O(n) and in worst case size of stack is O(h)// height of binary tree
void inorder2(Node* root)
{
	stack<Node*> s;
	Node* cur = root;
	while(true)
	{
		if(cur!=NULL)
		{
			s.push(cur);
			cur=cur->left;
		}
		else
		{
			if(s.empty())//if stack is empty
			{
				cout << endl;
				break;
			}
			// if cur is null
			cur = s.top();
			s.pop();
			cout << cur->data  << " ";
			cur = cur->right;
		}
	}
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
	inorder(root);
	cout << endl;
	
	inorder2(root);
	
	return 0;
}