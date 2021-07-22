bool checkBST(Node* root,int l,int r)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data >= l && root->data < r )
    {
        return checkBST(root->left,l,root->data) && checkBST(root->right,root->data,r);
    }
    return false;
    
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) 
{
    
    return checkBST(root,INT_MIN,INT_MAX);
   
}