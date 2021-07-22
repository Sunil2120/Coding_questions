#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* left ;
	struct node* right;
};
typedef struct node Node;


Node* newNode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printVector(vector<int>& path,int i)
{
	for(int j=i;j<path.size();j++)
	{
		cout << path[j] << " ";
	}
	cout << endl;
	return ;
}

void solve(Node* root,int k,vector<int>& path)
{
	if(root==NULL)
	{
		return ;
	}
	//push the current node to the path
	path.push_back(root->data);
	// check if k sum path is present in left
	solve(root->left,k,path);
	// check if k sum path is present in right
	solve(root->right,k,path);
	// we will check whether there is a path of sum k terminating at this root node
	int sum = 0;
	for(int i=path.size()-1;i>=0;i--)
	{
		sum+=path[i];
		if(sum==k)
		{
			printVector(path,i);
		}
	}
	// remove the current element from path
	path.pop_back();
	return ;
}
void print_k_sum(Node* root,int k)
{
	if(root==NULL)
	{
		return ;
	}
	vector<int> path;
	solve(root,k,path);
	return ;
}

int main()
{
	Node *root = newNode(1); 
    root->left = newNode(3); 
    root->left->left = newNode(2); 
    root->left->right = newNode(1); 
    root->left->right->left = newNode(1); 
    root->right = newNode(-1); 
    root->right->left = newNode(4); 
    root->right->left->left = newNode(1); 
    root->right->left->right = newNode(2); 
    root->right->right = newNode(5); 
    root->right->right->right = newNode(2); 
  
    int k = 5; 
    print_k_sum(root, k); 
	return 0;
}