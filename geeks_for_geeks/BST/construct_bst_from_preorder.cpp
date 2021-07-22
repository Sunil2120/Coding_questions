 TreeNode* solve(vector<int>& pre,int& index,int l,int h)
    {
        if(index==pre.size())
        {
            return NULL;
        }
        if(pre[index]>l && pre[index]<h)
        {
            TreeNode* temp=new TreeNode(pre[index]);
            index+=1;
            temp->left=solve(pre,index,l,temp->val);
            temp->right=solve(pre,index,temp->val,h);
            return temp;
        }
        return NULL;
        
    }