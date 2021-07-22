
// to reduce the time complexity we have used hash map
// where getting the index of the element in inorder is O(1)
// time complexity O(n)
Node* solve(int in[],int pre[],int start,int end,int& index,unordered_map<int,int>& hash)
{
    if(start > end)
    {
        return NULL;
    }
    Node* temp = new Node(pre[index]);
   
    index+=1;
    
    if(start==end)
    {
        return temp;
    }
    int cur_index = hash[temp->data];
    temp->left = solve(in,pre,start,cur_index-1,index,hash);
    temp->right = solve(in,pre,cur_index+1,end,index,hash);
    return temp;
    
}
Node* buildTree(int in[],int pre[], int n)
{
    unordered_map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        hash[in[i]]=i;
    }
    int index = 0;
    return solve(in,pre,0,n-1,index,hash);
}