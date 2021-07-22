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

void preorder(Node* root)
{
	if(root!=NULL)
	{
		//inorder(root->left);
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

// steps pop(print) push(right) push(left)
// time complexity O(n) and space complexity O(h)(worst case O(n))
void preorder2(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	stack<Node*> s;
	Node* cur = root;
	while(true)
	{
		if(cur!=NULL)
		{
			cout << cur->data << " ";
			s.push(cur);
			cur=cur->left;
		}
		else
		{
			if(s.size() ==0)//empty
			{
				cout << endl;
				return ;
			}
			cur = s.top();
			s.pop();
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
	preorder(root);
	cout << endl;
	
	preorder2(root);
	
	return 0;
}