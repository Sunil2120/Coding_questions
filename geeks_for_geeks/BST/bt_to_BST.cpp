

//Binary Tree to BST 

//Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
// Time complexity O(nlogn)
// space complexity O(n)
void inorder(Node* root,vector<int>& arr)
{
    if(root!=NULL)
    {
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
}

void inorder2(Node* root,int& index,vector<int>& arr)
{
    if(root!=NULL)
    {
        inorder2(root->left,index,arr);
        root->data = arr[index];
        index+=1;
        inorder2(root->right,index,arr);
    }
}

// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    inorder(root,arr);
    sort(arr.begin(),arr.end());
    int index = 0;
    inorder2(root,index,arr);
    return root;
}