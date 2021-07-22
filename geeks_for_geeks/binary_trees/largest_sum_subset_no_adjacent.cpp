#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int largest_sum_util(Node* root,map<Node*,int>& hash)
{
	if(root==NULL)
	{
		return 0;
	}
	// if cur node is already processed
	if(hash.find(root)!=hash.end())
	{
		return hash[root];
	}

	// if we include the cur node
	int total = root->data;
	if(root->left!=NULL)
	{
		total+=largest_sum_util(root->left->left,hash)+largest_sum_util(root->left->right,hash);
	}
	if(root->right!=NULL)
	{
		total+=largest_sum_util(root->right->left,hash)+largest_sum_util(root->right->right,hash);
	}

	// if we exclude the cur node
	int total2 = 0;
	total2 += largest_sum_util(root->left,hash)+largest_sum_util(root->right,hash);
	hash[root]=max(total,total2);
	return hash[root];
}
// METHOD - 1
// time complexity O(n^2)
// space complexity O(n)
int largest_sum(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	map<Node*,int> hash;
	return largest_sum_util(root,hash);
}

pair<int,int> helper(Node* root)
{
	if(root==NULL)
	{
		return make_pair(0,0);
	}
	pair<int,int> sum1 = helper(root->left);
	pair<int,int> sum2 = helper(root->right);
	pair<int,int> sum;
	// if current node is included
	sum.first = root->data + sum1.second + sum2.second;
	// if current node is excluded
	sum.second = max(sum1.first,sum1.second)+max(sum2.first,sum2.second);
	return sum;
}


// METHOD - 2 (efficient method)
// pair method
// Time complexity O(n) and auxillary space O(1)
// pair<int,int> where first indicates if current node is included
// pair<int,int> where second indicates if current node is not included
int solve2(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	pair<int,int> output = helper(root);
	return max(output.first,output.second);
}

int main()
{
	Node* root = newNode(10);
    root->left = newNode(1);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);
    root->left->right = newNode(3);
    root->left->right->left = newNode(4);
     root->left->right->right = newNode(5);
     cout << largest_sum(root) << endl;
    cout << solve2(root) << endl;
	return 0;
}