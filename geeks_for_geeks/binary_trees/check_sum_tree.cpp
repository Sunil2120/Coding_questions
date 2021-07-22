

// Given a Binary Tree. Check whether it is a Sum Tree or not.

// A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree . An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. 
// A leaf node is also considered as a Sum Tree.
pair<bool,int> solve(Node* root)
{
    if(root==NULL)
    {
        return make_pair(true,0);
    }
    if(root->left==NULL && root->right==NULL)
    {
        return make_pair(true,root->data);
    }
    pair<bool,int> left = solve(root->left);
    pair<bool,int> right = solve(root->right);
    if(left.first && right.first && root->data == left.second+right.second)
    {
        return make_pair(true,root->data + left.second+right.second);
    }
    return make_pair(false,root->data + left.second+right.second);
}
// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
    return solve(root).first;
}