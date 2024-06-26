// A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph, either ‘u’ or ‘v’ is in vertex cover. 
// Although the name is Vertex Cover, the set covers all edges of the given graph.
// The problem to find minimum size vertex cover of a graph is NP complete. 
// But it can be solved in polynomial time for trees. In this post a solution for Binary Tree is discussed. 
// The same solution can be extended for n-ary trees.

// The idea is to consider following two possibilities for root and recursively for all nodes down the root.
// 1) Root is part of vertex cover: In this case root covers all children edges. We recursively calculate size of vertex covers for left and right subtrees and add 1 to the result (for root).

// 2) Root is not part of vertex cover: In this case, both children of root must be included in vertex cover to cover all root to children edges. 
//  We recursively calculate size of vertex covers of all grandchildren and number of children to the result (for two children of root).

#include<bits/stdc++.h>
using namespace std;

struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 

// A utility function to create a node 
struct node* newNode( int data ) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

int solve(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return 0;//leaf node
	}
	// root is a part of vertex cover
	int temp1 = 1 + solve(root->left) + solve(root->right);
	// root is not a part of vertex cover
	int temp2 = 0;
	if(root->left!=NULL)
	{
		temp2+= 1 + solve(root->left->left)+solve(root->left->right);
	}
	if(root->right!=NULL)
	{
		temp2+= 1 + solve(root->right->left)+solve(root->right->right);
	}
	return min(temp1,temp2);

}

int main()
{
	struct node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25);
    cout << solve(root) << endl;
    return 0; 
}


