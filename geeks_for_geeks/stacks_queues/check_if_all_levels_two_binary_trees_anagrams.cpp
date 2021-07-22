#include<bits/stdc++.h>
using namespace std;

// Time complexity O(n)
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* create_node(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void level_order(Node* root,unordered_map<int,vector<int>>& hash)
{
	if(root==NULL)
	{
		return ;
	}
	queue<pair<Node*,int>> Q;
	Q.push(make_pair(root,1));
	while(!Q.empty())
	{
		pair<Node*,int> cur = Q.front();
		Q.pop();
		hash[cur.second].push_back(cur.first->data);
		if(cur.first->left!=NULL)
		{
			Q.push(make_pair(cur.first->left,cur.second+1));
		}
		if(cur.first->right!=NULL)
		{
			Q.push(make_pair(cur.first->right,cur.second+1));
		}
	}
	return ;

}
int levels(int n)
{
	int value = log2(n);
	value +=1;
	return value;
}

bool solve(Node* root,Node* root1,int n1,int n2)
{
	if(n1!=n2)
	{
		return false;
	}
	if(levels(n1)!=levels(n2))
	{
		return false;
	}
	if(root==NULL && root1!=NULL)
	{
		return false;
	}
	if(root!=NULL && root1==NULL)
	{
		return false;
	}
	unordered_map<int,vector<int>> hash1;
	unordered_map<int,vector<int>> hash2;
	level_order(root,hash1);
	level_order(root1,hash2);
	int total = levels(n1);
	for(int i=1;i<=total;i++)
	{
		vector<int> first = hash1[i];
		vector<int> second = hash2[i];
		if(first.size() != second.size())
		{
			return false;
		}
		sort(first.begin(),first.end());
		sort(second.begin(),second.end());
		for(int i=0;i<first.size();i++)
		{
			if(first[i]!=second[i])
			{
				return false;
			}
		}
	}
	return true;
}

// Node* insert(Node* root,int item)
// {
// 	if(root==NULL)
// 	{
// 		return root;
// 	}
// 	Node* temp = create_node(item);
// 	Node* cur = root;
// 	Node* prev = cur;
// 	while(cur!=NULL)
// 	{
// 		prev = cur;
// 		if(item <= cur->data)
// 		{
// 			cur=cur->left;
// 		}
// 		else
// 		{
// 			cur=cur->right;
// 		}
// 	}
// 	if(item <= prev->data)
// 	{
// 		prev->left = temp;
// 	}
// 	else
// 	{
// 		prev->right = temp;
// 	}
// 	return root;

// }

int main()
{
	int n1;
	int n2;
	cin >> n1 >> n2;
	Node* root = NULL;
	// for(int i=0;i<n1;i++)
	// {
	// 	int val;
	// 	cin >> val;
	// 	root = insert(root,val);
	// }
	Node* root1 = NULL;
	// for(int i=0;i<n2;i++)
	// {
	// 	int val;
	// 	cin >> val;
	// 	root1=insert(root1,val);
	// }
	root = create_node(10);
	root1 = create_node(10);
	root->left = create_node(2);
	root1->left = create_node(3);
	root->right = create_node(3);
	root1->right = create_node(2);
	root->right->left = create_node(4);
	root->right->right = create_node(5);
	root1->left->left = create_node(5);
	root1->left->right = create_node(4);
	cout << solve(root,root1,n1,n2) << endl;
	return 0;

}