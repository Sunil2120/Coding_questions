// path equal to given sum
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data=0;
	struct node* left=NULL;
	struct node* right=NULL;
};
typedef struct node node;



node* insert(node* root,int key)
{
	node* temp = new node();
	temp->data = key;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	node* cur = root;
	node* prev = NULL;
	while(cur!=NULL)
	{
		prev = cur;
		if(key < cur->data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	if(key < prev->data)
	{
		prev->left = temp;
	}
	else
	{
		prev->right = temp;
	}
	return root;
}

int solve(node* root,int sum,int temp)
{

	if(root==NULL)
	{
		return 0;
	}
	temp += root->data;
	int count = 0;
	if(temp==sum)
	{
		count+=1;
	}
	
	if(root->left!=NULL)
	{
		count+=solve(root->left,sum,temp);
	}
	if(root->right!=NULL)
	{
		count+=solve(root->right,sum,temp);
	}
	return count;
}

void inorder(node* root,int sum,int& count)
{
	if(root!=NULL)
	{
		inorder(root->left,sum,count);
		count+=solve(root,sum,0);
		inorder(root->right,sum,count);
	}
}

int main()
{
	node* root = NULL;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int value;
		cin >> value;
		root = insert(root,value);
	}
	int sum ;
	cin >> sum;
	int count = 0;
	inorder(root,sum,count);
	cout << count << endl;
	return 0;
}