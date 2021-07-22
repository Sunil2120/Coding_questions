#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

// Method 1 - two for loops
// Method 2 - BST
struct node
{
	int data;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node Node;

Node* newNode(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
}

void insert(Node*& root,int item,Node*& suc)
{
	if(root==NULL)
	{
		root = newNode(item);
		return ;
	}
	if(item < root->data)
	{
		//left(inorder successor of left is it's root)
		suc = root;
		insert(root->left,item,suc);
	}
	else if(item > root->data)
	{
		//right
		insert(root->right,item,suc);
	}
	return ;
}
// method-2 using BST
void solve2(vector<int>& arr,int n)
{
	if(n==0)
	{
		return ;
	}
	Node* root = NULL;
	//step1 start traversing from the back(right to left)
	for(int i=n-1;i>=0;i--)
	{
		
		Node* suc = NULL;
		//step2 insert into binary tree and note down inorder successor
		insert(root,arr[i],suc);
		if(suc!=NULL)
		{
			arr[i]=suc->data;//replace with inorder successor
		}
		else
		{
			arr[i]=-1;
		}
	}
	return ;
}

int findmin(vector<int>& arr,int start,int n)
{
	int index = -1;
	int min_value = INT_MAX;
	for(int i=start+1;i<n;i++)
	{
		//greater than start and least one
		if(arr[i] > arr[start])
		{
			if(arr[i] < min_value)
			{
				min_value = arr[i];
				index = i;
			}
		}
	}
	return index;
}

void solve(vector<int>& arr,int n)
{
	if(n==0)
	{
		return ;
	}
	for(int i=0;i<n;i++)
	{
		int j = findmin(arr,i,n);
		int temp = arr[i];
		if(j==-1)
		{
			arr[i]=-1;
		}
		else
		{
			arr[i]=arr[j];
			
		}
	}
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
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}