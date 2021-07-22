void inorder(Node* root,int& count,int& value,int k)
{
    if(root!=NULL)
    {
        inorder(root->left,count,value,k);
        count+=1;
        if(count==k)
        {
            value = root->data;
            return ;
        }
        inorder(root->right,count,value,k);
    }
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int K)
{
    int value = -1;
    int count = 0;
    inorder(root,count,value,K);
    return value;
}