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

bool findpath(Node* root,vector<int>& path,int key)
{
	if(root==NULL)
	{
		return false;
	}
	path.push_back(root->data);
	if(root->data == key)
	{
		return true;
	}
	bool left = findpath(root->left,path,key);
	bool right = findpath(root->right,path,key);
	if(left || right)// if any one of the them found the key
	{
		return true;
	}
	path.pop_back();
	return false;
}
// method-1
// Time Complexity: The time complexity of the above solution is O(n). 
// The tree is traversed twice, and then path arrays are compared. 
//The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). 
//If the root doesn’t match with any of the keys, we recur for the left and right subtree. The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, LCA lies in the right subtree.  
int findLCA(Node* root,int n1,int n2)
{
	if(root==NULL)
	{
		return -1;
	}
	vector<int> path1;
	vector<int> path2;
	bool first = findpath(root,path1,n1);
	bool second = findpath(root,path2,n2);
	// either one of them is not present
	if(first==false || second==false)
	{
		return -1;
	}
	// we will compare their paths
	// for(int i=0;i<path1.size();i++)
	// {
	// 	cout << path1[i] << " ";
	// }
	// cout << endl;
	// for(int i=0;i<path2.size();i++)
	// {
	// 	cout << path2[i] << " ";
	// }
	// cout << endl;
	int i;
	 for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

// method-2(efficient single traversal)
// time complexity single traversal O(n)
// auxillary space O(1)
Node* findLCA2(Node* root,int n1,int n2)
{
	if(root==NULL)
	{
		return NULL;
	}
	// if cur root is either n1 or n2 return root
	if(root->data == n1 || root->data == n2)
	{
		return root;
	}
	// we will call left subtree
	Node* left = findLCA2(root->left,n1,n2);
	// we will call right subtree
	Node* right = findLCA2(root->right,n1,n2);
	if(left!=NULL && right!=NULL)
	{
		// leftsubtree contains one node and right subtree contains another node
		return root;// lowest common ancestor
	}
	// Otherwise check if left subtree or right subtree is LCA
	// if left subtree is null (left subtree doesnot contains n1 and n2 so right)
	if(left==NULL)
	{
		return right;
	}
	return left;
}

int main()
{
	Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)<< endl;
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)<< endl;
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)<< endl;
    cout << endl;
    cout << "LCA(4, 5) = " << findLCA2(root, 4, 5)->data << endl;
    cout << "nLCA(4, 6) = " << findLCA2(root, 4, 6)->data<< endl;
    cout << "nLCA(3, 4) = " << findLCA2(root, 3, 4)->data<< endl;
    cout << "nLCA(2, 4) = " << findLCA2(root, 2, 4)->data<< endl;
    return 0;
}