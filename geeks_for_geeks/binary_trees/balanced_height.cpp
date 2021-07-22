int solve(Node* root)
{
   if(root==NULL)
   {
       return 0;
   }
   return max(solve(root->left),solve(root->right))+1;
}


// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    if(left&&right && abs(solve(root->left)-solve(root->right)) <= 1)
    {
        return true;   
    }
    return false;
    
}