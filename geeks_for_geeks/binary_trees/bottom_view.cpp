vector<int> bottomView(Node *root)
{
   vector<int> output;
   if(root==NULL)
   {
       return output;
   }
    int min_level = INT_MAX;
    int max_level = INT_MIN;
    queue<pair<Node*,int>> Q;
    unordered_map<int,vector<int>> hash;
    Q.push(make_pair(root,0));
    while(!Q.empty())
    {
        Node* first = Q.front().first;
        int second = Q.front().second;
        hash[second].push_back(first->data);
        Q.pop();
        min_level = min(min_level,second);
        max_level = max(max_level,second);
        if(first->left!=NULL)
        {
               Q.push(make_pair(first->left,second-1));
        }
        if(first->right!=NULL)
        {
            Q.push(make_pair(first->right,second+1));
        }
    }
    for(int i=min_level;i<=max_level;i++)
    {
        output.push_back(hash[i].back());
    }
    return output;
}