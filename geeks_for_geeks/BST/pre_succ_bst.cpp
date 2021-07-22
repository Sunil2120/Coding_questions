// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->key == key)
    {
        if(root->left!=NULL)
        {
            Node* temp = root->left;
            while(temp!=NULL && temp->right!=NULL)
            {
                temp=temp->right;
            }
            pre = temp;
        }
        if(root->right!=NULL)
        {
            Node* temp = root->right;
            while(temp!=NULL && temp->left!=NULL)
            {
                temp = temp->left;
            }
            suc = temp;
        }
        return ;
    }
    if(key < root->key)
    {
        suc = root;
        // even if key is not present this can be suc
        return findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        pre = root;
         // even if key is not present this can be pre
        return findPreSuc(root->right,pre,suc,key);
    }
} 