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

void solve(node* root,map<int,vector<int>>& hash,int value)
{
	if(root==NULL)
	{
		return ;
	}
	// if(hash[value].size()!=0)
	// {
	// 	int first = hash[value].back;
	// 	int cur = root->data;
	// 	if(cur < first)
	// 	{
	// 		hash[value].pop_back();
	// 		hash[value].push_back(cur);
	// 		hash[value].push_back(first);
	// 	}
	// 	else
	// 	{
	// 		hash[value].push_back(cur);
	// 	}
	// }
	// hash[value].push_back(root->data);
	// cout << root->data << " " << value << endl;
	// solve(root->left,hash,value-1);
	// solve(root->right,hash,value+1);
	queue<pair<node*,int>> Q;
	Q.push(make_pair(root,0));
	while(!Q.empty())
	{
		pair<node*,int> temp = Q.front();
		node* cur = temp.first;
		int value = temp.second;
		Q.pop();
		hash[value].push_back(cur->data);
		if(cur->left!=NULL)
		{
			Q.push(make_pair(cur->left,value-1));
		}
		if(cur->right!=NULL)
		{
			Q.push(make_pair(cur->right,value+1));
		}
	}

	return ;
}
int main()
{

	int n;
	cin >> n;
	node* root = NULL;
	for(int i=0;i<n;i++)
	{
		int value;
		cin >> value;
		root = insert(root,value);
	}
	map<int,vector<int>> hash;
	solve(root,hash,0);
	map<int,vector<int>> :: iterator it;
	for(it=hash.begin();it!=hash.end();it++)
	{
		int m = (*it).second.size();
		for(int i=0;i<m;i++)
		{
			cout << ((*it).second)[i] << " ";
		}
		cout << endl;
	}
	return 0;

}