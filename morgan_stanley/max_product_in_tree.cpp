#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;
	struct node* left = NULL;
	struct  node* right = NULL;
};

typedef struct node node;

int solve(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	queue<pair<node*,int>> Q;
	int max_value = INT_MIN;

	Q.push(make_pair(root,root->data));
	while(Q.size()!=0)
	{
		node* cur =Q.front().first;
		int cur_value = Q.front().second;
		Q.pop();
		//explore it's neighbours
		if(cur->left!=NULL)
		{
			Q.push(make_pair(cur->left,cur_value*cur->left->data));
		}
		if(cur->right!=NULL)
		{
			Q.push(make_pair(cur->right,cur_value*cur->right->data));
		}
		if(cur->left==NULL && cur->right==NULL)//leaf node
		{
			max_value = max(max_value,cur_value);
		}
	}
	return max_value;
}

node* getnode(int value)
{
	node* temp = new node();
	temp->left=NULL;
	temp->right=NULL;
	temp->data = value;
	return temp;
}

int main()
{
	node* root = NULL;
	root = getnode(2);
	root->left = getnode(3);
	root->right = getnode(4);
	root->left->left = getnode(5);
	root->left->right = getnode(7);
	root->right->left = getnode(8);
	root->right->right = getnode(6);
	cout << solve(root) << endl;
	return 0;


}