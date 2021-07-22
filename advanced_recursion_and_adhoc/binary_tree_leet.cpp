#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data=0;
	struct node* left=NULL;
	struct node* right=NULL;

};
typedef struct node NODE;

NODE* insert(NODE* root,int key)
{
	NODE* temp = new NODE();
	temp->data = key;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	NODE* cur = root;
	NODE* prev = NULL;
	while(cur!=NULL)
	{
		prev = cur;
		if(key <= cur->data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
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

void inorder(NODE* root,vector<int>& leaf_nodes)
{
	if(root!=NULL)
	{
		inorder(root->left,leaf_nodes);
		if(root->left==NULL && root->right==NULL)
		{
			leaf_nodes.push_back(root->data);
		}
		inorder(root->right,leaf_nodes);
	}
}

NODE* LCA(NODE* root,int n1,int n2)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==n1 || root->data==n2)
	{
		return root;
	}
	NODE* l = LCA(root->left,n1,n2);
	NODE* r = LCA(root->right,n1,n2);
	// if both l and r are NON_NULL one is present in l and one is present in r
	// if any one is NULL both are present in either l or r
	if(l!=NULL && r!=NULL)
	{
		return root;
	}
	return l!=NULL?l:r;
}

int solve(NODE* root,int first,int count)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->data==first)
	{
		return count;
	}
	int l = solve(root->left,first,count+1);
	int  r = solve(root->right,first,count+1);
	if(l==0)
	{
		return r;
	}
	else
	{
		return l;
	}
	return 0;

}



int main()
{
	int n,d;
	cin >> n >> d;
	NODE* root = NULL;
	int count = 0;
	vector<int> leaf_nodes;

	for(int i=0;i<n;i++)
	{
		int value ;
		cin >> value;
		root = insert(root,value);
	}
	inorder(root,leaf_nodes);
	for(int i=0;i<leaf_nodes.size();i++)
	{
		for(int j=i+1;j<leaf_nodes.size();j++)
		{
			NODE* temp = LCA(root,leaf_nodes[i],leaf_nodes[j]);
			int sum = solve(temp,leaf_nodes[i],0) + solve(temp,leaf_nodes[j],0);
			cout << sum << endl;
			if(sum <= d)
			{
				count+=1;
			}
		}

		
	}

	cout << count <<  endl;


	return 0;


}