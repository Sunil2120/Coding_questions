

//Time complexity = O(n) + O(n) (two inorders)
// auxillary space = O(n) (hash map)
// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. 
// Your task is to complete the function countPairs(), 
// that returns the count of all pairs from both the BSTs whose sum is equal to x.
void inorder(Node* root,unordered_map<int,bool>& hash)
{
    if(root!=NULL)
    {
        inorder(root->left,hash);
        hash[root->data]=true;
        inorder(root->right,hash);
    }
}

void inorder2(Node* root,int& count,unordered_map<int,bool>& hash,int x)
{
    if(root!=NULL)
    {
        inorder2(root->left,count,hash,x);
        if(hash[x-root->data])
        {
            count+=1;
        }
        inorder2(root->right,count,hash,x);
    }
}
// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
    unordered_map<int,bool> hash;
    inorder(root2,hash);
    int count = 0;
    inorder2(root1,count,hash,x);
    return count;
}