#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2)
// Auxiliary Space: O(N)
struct node
{
	int data;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node Node;

Node* create_node(int val)
{
	Node* temp = new Node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int findIndex(string input,int start,int end)
{
	stack<char> s;
	for(int i=start;i<=end;i++)
	{
		if(input[i]==')')
		{
			while(s.top()!='(')
			{
				s.pop();
			}
			s.pop();
			if(s.empty())
			{
				return i;
			}
		}
		else
		{
			s.push(input[i]);
		}
	}
	return -1;
}

Node* construct_tree(string input,int start,int end)
{
	if(start > end)
	{
		return NULL;
	}
	Node* temp = create_node(input[start] -'0');
	int index  = -1;
	if(start+1 <= end && input[start+1]=='(')
	{
		index = findIndex(input,start+1,end);
	}
	if(index!=-1)
	{
		temp->left = construct_tree(input,start+2,index-1);
		temp->right = construct_tree(input,index+2,end-1);
	}
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


int main()
{
	string input;
	cin >> input;
	Node* root = construct_tree(input,0,input.size()-1);
	inorder(root);

	return 0;
}