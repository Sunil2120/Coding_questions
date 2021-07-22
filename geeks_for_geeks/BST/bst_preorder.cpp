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
	Node* temp= new Node();
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* solve1Helper(int& preindex,vector<int>& arr,int n,int left,int right)
{
	if(preindex >= n || left > right)
	{
		return NULL;
	}
	Node* root = newNode(arr[preindex]);
	preindex+=1;
	if(left==right)
	{
		return root;
	}
	// we will find the right node(first element after root which is greater than root->data)
	// remembering we are checking in preorder
	int index = -1;
	for(int i=left;i<=right;i++)
	{
		if(arr[i] > root->data)
		{
			index = i;
			break;
		}
	}
	// elements to the left of index are left subtree of node
	// elements including the index and right elements are right subtree of node
	if(preindex < n)
	{
		root->left = solve1Helper(preindex,arr,n,preindex,index-1);
	}
	if(preindex < n)
	{
		root->right = solve1Helper(preindex,arr,n,index,right);
	}
	return root;

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

// Method-1 O(n^2)
void solve1(vector<int>& arr,int n)
{
	Node* root = NULL;
	int preindex = 0;
	root = solve1Helper(preindex,arr,n,0,n-1);
	inorder(root);
	cout << endl;
	return ;
}

Node* solve2Helper(int& preindex,vector<int>& arr,int n,int min,int max)
{
	if(preindex >= n)
	{
		return NULL;
	}
	Node* root = NULL;
	int data = arr[preindex];
	
	if(data >= min && data < max)
	{
		root = newNode(arr[preindex]);
		preindex+=1;
		if(preindex < n)
		{
			root->left = solve2Helper(preindex,arr,n,min,root->data);
		}
		if(preindex < n)
		{
			root->right = solve2Helper(preindex,arr,n,root->data,max);
		}
	}
	return root;
}

// Method-2 O(n)
void solve2(vector<int>& arr,int n)
{
	Node* root = NULL;
	int preindex = 0;
	root = solve2Helper(preindex,arr,n,INT_MIN,INT_MAX);
	inorder(root);
	cout << endl;
	return ;
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
	solve2(arr,n);
	return 0;
}