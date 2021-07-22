
// The idea is to do reverse inorder traversal of BST. Keep a count of nodes visited.
// The reverse inorder traversal traverses all nodes in decreasing order, i.e, 
//visit the right node then centre then left and continue traversing the nodes recursively.
// While doing the traversal, keep track of the count of nodes visited so far.
// When the count becomes equal to k, stop the traversal and print the key.
// Time Complexity: O(h + k).
// The code first traverses down to the rightmost node which takes O(h) time, then traverses k elements in O(k) time. Therefore overall time complexity is O(h + k).
// Auxiliary Space: O(1).
// As no extra space is needed.
void inorder(Node* root,int& count,int k,int& value)
{
    if(root!=NULL)
    {
        inorder(root->right,count,k,value);
        count+=1;
        if(count==k)
        {
            value = root->data;
            return ;
        }
        inorder(root->left,count,k,value);
    }
}
// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
   int value = -1;
   int count = 0;
   inorder(root,count,K,value);
   return value;
}