#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

// Time complexity : O(m)(inorder1) + O(n)(inorder2) + O(m+n)(merge) = O(m+n)
// space complexity : O(m+n)(merge function)

struct node
{
	int data;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node Node;


Node* newNode(int val)
{
	Node* temp = new Node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* root,int key)
{
	Node* temp = newNode(key);
	if(root==NULL)
	{
		root = temp;
		return root;
	}
	Node* cur = root;
	Node* prev = NULL;
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

void print_inorder(Node* root)
{
	if(root!=NULL)
	{
		print_inorder(root->left);
		cout << root->data << " ";
		print_inorder(root->right);
	}
	
}

void inorder(Node* root,vector<int>& arr)
{
	if(root!=NULL)
	{
		inorder(root->left,arr);
		arr.push_back(root->data);
		inorder(root->right,arr);
	}
}

vector<int> merge(vector<int>& first,vector<int>& second)
{
	int n1 = first.size();
	int n2 = second.size();
	vector<int> output;
	if(n1==0 && n2==0)
	{
		return output;
	}
	if(n1==0)
	{
		return second;
	}
	if(n2==0)
	{
		return first;
	}
	int i=0;
	int j=0;
	while(i<n1 && j<n2)
	{
		if(first[i] <= second[j])
		{
			output.push_back(first[i]);
			i+=1;
		}
		else
		{
			output.push_back(second[j]);
			j+=1;
		}
	}
	while(i<n1)
	{
		output.push_back(first[i]);
		i+=1;
	}
	while(j<n2)
	{
		output.push_back(second[j]);
		j+=1;
	}
	return output;
}

Node* construct_tree(vector<int>& total,int left,int right)
{
	if(left > right)
	{
		return NULL;
	}
	int mid = (left+right)/2;
	Node* root = newNode(total[mid]);
	if(left==right)
	{
		return root;//only one node
	}
	root->left = construct_tree(total,left,mid-1);
	root->right = construct_tree(total,mid+1,right);
	return root;
}

Node* merge_bst(Node* root1,Node* root2)
{
	vector<int> first;
	vector<int> second;
	inorder(root1,first);
	inorder(root2,second);
	vector<int> total = merge(first,second);
	for(int i=0;i<total.size();i++)
	{
		cout << total[i] << " ";
	}
	cout << endl;
	// construct bst from sorted binary tree
	Node* root = construct_tree(total,0,total.size()-1);
	return root;
}

int main()
{
	int n1,n2;
	cin >> n1 >> n2;
	Node* root1 = NULL;
	while(n1--)
	{
		int val;
		cin >> val;
		root1 = insert(root1,val);
	}

	Node* root2 = NULL;
	while(n2--)
	{
		int val;
		cin >> val;
		root2 = insert(root2,val);
	}

	Node* root = merge_bst(root1,root2);
	print_inorder(root);

	return 0;
}