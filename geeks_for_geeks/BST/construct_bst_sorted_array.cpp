#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* newNode(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

Node* Helper(vector<int>& arr,int left,int right)
{
	if(left > right)
	{
		return NULL;
	}
	int mid = (left+right)/2;
	Node* root = newNode(arr[mid]);
	if(left==right)
	{
		return root;
	}
	root->left = Helper(arr,left,mid-1);
	root->right = Helper(arr,mid+1,right);
	return root;
}

Node* solve(vector<int>& arr,int n)
{
	return Helper(arr,0,n-1);
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	Node* root = solve(arr,n);
	inorder(root);
	cout << endl;
	return 0;
}