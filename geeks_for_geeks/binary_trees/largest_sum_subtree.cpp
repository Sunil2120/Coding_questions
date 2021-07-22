#include<bits/stdc++.h>
using namespace std;


struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
// Function to create new tree node. 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

int helper(Node* root,int& ans)
{
	if(root==NULL)
	{
		return 0;
	}
	int left = helper(root->left,ans);
	int right = helper(root->right,ans);
	int total = root->data + left + right;
	ans = max(ans,total);
	return total;
}

int solve(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ans = INT_MIN;
	int temp = helper(root,ans);
	return ans;

}


int main()
{
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  	
    cout << solve(root) << endl;
    return 0; 
}