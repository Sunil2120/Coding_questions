
// diagonal view
// same as top view,left view,bottom view,right view
// only difference is when we go left increament and when we go right do nothing.
void solve(Node* root,int d,map<int,vector<int>>& hash)
{
    if(root==NULL)
    {
        return ;
    }
    hash[d].push_back(root->data);
    //left
    solve(root->left,d+1,hash);
    //right
    solve(root->right,d,hash);
    return ;
}

vector<int> diagonal(Node *root)
{
    map<int,vector<int>> hash;
    vector<int> output;
    solve(root,0,hash);
    for(auto it:hash)
    {
        vector<int> temp = it.second;
        for(auto i:temp)
        {
            output.push_back(i);
        }
    }
    return output;
}