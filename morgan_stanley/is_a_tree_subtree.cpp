// Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
// A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.
// bool isIdentical(Node* T,Node* S)
{
    if(T==NULL && S==NULL)
    {
        return true;
    }
    if((T==NULL && S!=NULL) || (T!=NULL && S==NULL))
    {
        return false;
    }
    if(T->data != S->data)
    {
        return false;
    }
    return (isIdentical(T->left,S->left) && isIdentical(T->right,S->right));
}

void inorder(Node* T,Node* S,int& check)
{
    if(T!=NULL)
    {
        inorder(T->left,S,check);
        if(T->data == S->data)
        {
            bool temp = isIdentical(T,S);
            if(temp==true)
            {
                check = 1;
                return ;
            }
        }
        inorder(T->right,S,check);
    }
    return ;
}
/*yu are required to
complete this function */
bool isSubTree(Node* T, Node* S) {
    // Your code here
    int check = 0;
    // return 1 if S is subtree of T else 0
    inorder(T,S,check);
    if(check==1)
    {
        return true;
    }
    return false;
    
    
}