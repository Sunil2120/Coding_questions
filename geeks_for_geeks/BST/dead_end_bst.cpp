
// Given a Binary search Tree that contains positive integer values greater then 0. 
// The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. 
// Here Dead End means, we are not able to insert any element after that node.


bool solve(Node* root,int low,int high)
{
    if(root==NULL)
    {
        return false;
    }
    bool left = solve(root->left,low,root->data);
    bool right = solve(root->right,root->data,high);
    if(left || right)//if deadend found
    {
        return true;
    }
    if( low+1 == root->data && root->data+1 == high)//current node is deadend
    {
        return true;
    }
    return false;
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    return solve(root,0,INT_MAX);// only positive elements so minvalue is 0
}