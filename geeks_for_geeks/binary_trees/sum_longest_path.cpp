 
// we are traversing all nodes once so
// time complexity O(n)
// space complexity O(n)(hash map)
 void solve(Node* root,int cur,int cur_level,int& max_depth,unordered_map<int,int>& hash)
{
    if(root==NULL)
    {
        return ;
    }
    cur+= root->data;
    hash[cur_level]=max(hash[cur_level],cur);
    if(root->left==NULL && root->right==NULL)
    {
        max_depth = max(max_depth,cur_level);
        return ;
    }
    solve(root->left,cur,cur_level+1,max_depth,hash);
    solve(root->right,cur,cur_level+1,max_depth,hash);
}
// your task is to complete this function
int sumOfLongRootToLeafPath(Node* root)
{
    int max_depth = 0;
    unordered_map<int,int> hash;
    solve(root,0,0,max_depth,hash);
    return hash[max_depth];
}