#include<bits/stdc++.h>
using namespace std;



struct node
{
	int data;
	struct node* left=NULL;
	struct node* right = NULL;
};
typedef struct node  Node;

Node* newNode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}

void vertical_order(Node* root,unordered_map<int,vector<int>>& m,int cur)
{
	//preorder
	// if(root!=NULL)
	// {
	// 	m[cur].push_back(root->data);
	// 	vertical_order(root->left,m,cur-1);
	// 	vertical_order(root->right,m,cur+1);
	// }
	// return;
	queue<pair<Node*,int>> Q;
	if(root==NULL)
	{
		return ;
	}
	Q.push(make_pair(root,0));
	while(!Q.empty())
	{
		pair<Node*,int> cur = Q.front();
		Q.pop();
		m[cur.second].push_back(cur.first->data);
		if(cur.first->left!=NULL)
		{
			Q.push(make_pair(cur.first->left,cur.second-1));
		}
		if(cur.first->right!=NULL)
		{
			Q.push(make_pair(cur.first->right,cur.second+1));
		}
	}
	return ;
}


int main()
{
	
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4);
    root->left->right=newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7); 
	unordered_map<int,vector<int>> m;
	vertical_order(root,m,0);
	int min_value = INT_MAX;
	int max_value = INT_MIN;
	unordered_map<int,vector<int>> :: iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		min_value = min(min_value,it->first);
		max_value = max(max_value,it->first);
	}
	vector<int> top;
	vector<int> buttom;
	if(min_value!=INT_MAX && max_value!=INT_MIN)
	{
		for(int i=min_value;i<=max_value;i++)
		{
			if(m[i].size()!=0)
			{
				top.push_back(m[i][0]);
				buttom.push_back(m[i].back());
			}
		}
	}
	for(int i=0;i<top.size();i++)
	{
		cout << top[i] << " ";
	}
	cout << endl;
	for(int i=0;i<buttom.size();i++)
	{
		cout << buttom[i] << " ";
	}
	cout << endl;
	return 0;
	return 0;
}