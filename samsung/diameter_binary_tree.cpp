pair<int,int> solve(Node* root)
{
    if(root==NULL)
    {
        return make_pair(0,0);
    }
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    int first = max(left.first,right.first)+1;
    int second = max(left.second,max(right.second,left.first+right.first+1));
    return make_pair(first,second);
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    if(node==NULL)
    {
        return 0;
    }
    pair<int,int> output = solve(node);
    return output.second;
}
