
//Min distance between two given nodes of a Binary Tree 

//Given a binary tree and two node values your task is to find the minimum distance between them.


// Time complexity => lca O(n) + findpath O(n) + findpath O(n) => O(3*n) => O(n)
// auxillary space = O(1)
Node* lca(Node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data == a || root->data == b)
    {
        return root;
    }
    Node* left = lca(root->left,a,b);
    Node* right = lca(root->right,a,b);
    if(left && right)
    {
        return root;
    }
    return left?left:right;
}
void findpath(Node* root,int key,int count,int& ans)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->data == key)
    {
        ans = count;
        return ;
    }
    findpath(root->left,key,count+1,ans);
    findpath(root->right,key,count+1,ans);
    return ;
}
int findDist(Node* root, int a, int b) {
    Node* temp = lca(root,a,b);
    int ans = -1;
    findpath(temp,a,0,ans);
    int first = ans;
    ans = -1;
    findpath(temp,b,0,ans);
    int second = ans;
    if(first==-1 || second==-1)
    {
        return -1;
    }
    return first+second;
}