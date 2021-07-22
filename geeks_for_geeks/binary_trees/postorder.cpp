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

void postorder(Node* root)
{
	if(root!=NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
// steps pop(print) push(right) push(left)
// time complexity O(n) and space complexity O(h)(worst case O(n))
// refer tushar roy's video you tube
void postorder2(Node* root)
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
			if(s.empty())
			{
				cout << endl;
				return ;//stack is empty and cur is null
			}
			Node* temp = s.top()->right;
			if(temp==NULL)
			{
				temp = s.top();
				s.pop();
				cout << temp->data << " ";
				while(!s.empty() && temp == s.top()->right)
				{
					temp = s.top();
					s.pop();
					cout << temp->data << " ";

				}
			}
			else
			{
				cur = temp;
			}
			
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
	postorder(root);
	cout << endl;
	
	postorder2(root);
	
	return 0;
}