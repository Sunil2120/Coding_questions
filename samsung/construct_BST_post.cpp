#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node Node;


Node* newnode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	return temp;
}
Node* solve(vector<int>& arr,int l,int cur)
{
	Node* root = newnode(arr[cur]);
	if(l==cur)
	{
		return root;
	}
	int left_node=-1;
	int right_node = -1;
	for(int i=cur-1;i>=l;i--)
	{
		if(arr[i] < arr[cur])
		{
			left_node = i;
			break;
		}
	}
	for(int i=cur-1;i>=l;i--)
	{
		if(arr[i] > arr[cur])
		{
			right_node = i;
			break;
		}
	}
	if(left_node!=-1)
	{
		root->left = solve(arr,l,left_node);
	}
	if(right_node!=-1 )
	{
		if(left_node!=-1)
		{
			root->right = solve(arr,left_node+1,right_node);
		}
		else
		{
			root->right = solve(arr,l,right_node);
		}
		
	}
	return root;
}

void postorder(Node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
		
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}
	Node* root=NULL;
	root = solve(arr,0,n-1);
	postorder(root);
	cout << endl;

	return 0;
}