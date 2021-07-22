#include<bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    Node *left, *right;
};
 

struct Node* getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorder(Node* root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void balance(Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->left!=NULL && root->right!=NULL)
	{
		if(root->left->data > root->right->data)
		{
			Node* temp = root->left;
			root->left = root->right;
			root->right = temp;
		}
	}
	balance(root->left);
	balance(root->right);
	return ;
}


void heapify(vector<int>& arr,int n,int i)
{
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<n && arr[l] < arr[smallest])
	{
		smallest = l;
	}
	if(r<n && arr[r] < arr[smallest])
	{
		smallest = r;
	}
	if(smallest!=i)
	{
		int temp = arr[smallest];
		arr[smallest]=arr[i];
		arr[i]=temp;
		heapify(arr,n,smallest);
	}
}
void convertToMinHeapUtil(Node* root)
{
	vector<int> arr;
	queue<Node*> Q;
	Q.push(root);
	while(Q.size() > 0)
	{
		Node* cur = Q.front();
		Q.pop();
		arr.push_back(cur->data);
		if(cur->left!=NULL)
		{
			Q.push(cur->left);
		}
		if(cur->right!=NULL)
		{
			Q.push(cur->right);
		}
	}
	int n = arr.size();
	int start = (n/2)-1;
	for(int i=start;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	int i=0;
	Q.push(root);
	while(Q.size() > 0)
	{
		Node* cur = Q.front();
		Q.pop();
		cur->data = arr[i];
		i+=1;
		if(cur->left!=NULL)
		{
			Q.push(cur->left);
		}
		if(cur->right!=NULL)
		{
			Q.push(cur->right);
		}
	}
	balance(root);
	return ;
}


int main()
{
    // BST formation
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 	preorder(root);
 	cout << endl;
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorder(root);
 
    return 0;
}