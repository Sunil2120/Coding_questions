#include<bits/stdc++.h>
using namespace std;

// If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
// If no. of nodes are odd : then median = (n+1)/2th node.

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

Node* insert(Node* root,int key)
{
	Node* temp = newNode(key);
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	Node* cur = root;
	Node* prev = NULL;
	while(cur!=NULL)
	{
		prev = cur;
		if(key <= cur->data)
		{
			cur=cur->left;
		}
		else
		{
			cur=cur->right;
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



void inorder(Node* root)
{
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int countNodes(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return countNodes(root->left)+countNodes(root->right)+1;
}

void inorder2(Node* root,int& count,int& value,int k)
{
	if(root!=NULL)
	{
		inorder2(root->left,count,value,k);
		count+=1;
		if(count==k)
		{
			value = root->data;
			return ;
		}
		inorder2(root->right,count,value,k);
	}
}



// time O(n)(inorder traversal)
// space O(n) (call stack)
//To find the median, we need to find the Inorder of the BST because its Inorder will be in sorted order and then find the median i.e.

//The idea is based on K’th smallest element in BST using O(1) Extra Space
int findmedian(Node* root)
{
	int count = countNodes(root);
	// if(count is odd)
	int k;
	int ans = -1;
	if((count%2)!=0)
	{
		// if n is odd then the median is (n+1)/2 node
		k = (count+1)/2;
		int value = 0;
		int cur = 0;
		inorder2(root,cur,value,k);
		ans = value;
	}
	else
	{
		// if n is even then the median is ((n/2) + (n/2)+1 )/2;
		k = (count)/2;
		int value = 0;
		int cur = 0;
		inorder2(root,cur,value,k);
		ans = value;
		value  = 0;
		cur = 0;
		k +=1;
		inorder2(root,cur,value,k);
		ans += value;
		ans = ans/2;

	}
	return ans;

}

int main()
{
	int n;
	cin >> n;
	Node* root = NULL;
	while(n--)
	{
		int data;
		cin >> data;
		root = insert(root,data);
	}
	inorder(root);
	cout << endl;
	cout << findmedian(root) << endl;
	return 0;
}