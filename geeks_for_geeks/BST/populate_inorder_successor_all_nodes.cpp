// Populate Inorder Successor for all nodes 

// Solution (Use Reverse Inorder Traversal) 
// Traverse the given tree in reverse inorder traversal and keep track of previously visited node. When a node is being visited, assign previously visited node as next.

// Given a Binary Tree, write a function to populate next pointer for all nodes. 
// The next pointer for every node should be set to point to inorder successor.

// in inorder we don't know what is next node
// so we shd go for reverse  inorder

// Time complexity O(n)
// auxillary space O(1)

/* Set next of p and all descendents of p by traversing them in reverse Inorder */

/*
Node Structure

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};
*/
// reverse inorder
void inorder(struct node* root,struct node*& prev)
{
    if(root!=NULL)
    {
        inorder(root->right,prev);
        root->next = prev;
        prev = root;
        inorder(root->left,prev);
    }
}

void populateNext(struct node* p)
{

    //we need inorder successor
    // if we do inorder we won't know next node
    // so we will do reverse inorder
    struct node* prev = NULL;
    inorder(p,prev);
    return ;

}
