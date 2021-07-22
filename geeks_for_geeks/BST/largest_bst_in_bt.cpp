//Largest BST in a BT
//Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.


//https://practice.geeksforgeeks.org/problems/largest-bst/1#


// Time complexity O(n) and auxillary space O(1)
// refer Tushar roy's video(you tube)(mandatory)
struct Info
{
    bool check;
    int size;
    int min;
    int max;
};

Info solve(Node* root)
{
    if(root==NULL)
    {
        return {true,0,INT_MAX,INT_MIN};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {true,1,root->data,root->data};
    }
    Info l = solve(root->left);
    Info r = solve(root->right);
    Info result ;
    if(l.check==true && r.check==true && root->data > l.max && root->data < r.min)
    {
        result.check = true;
        result.size = l.size + r.size + 1;
        result.min = min(l.min,min(root->data,r.min));
        result.max = max(l.max,max(root->data,r.max));
        return result;
    }
    result.size = max(l.size,r.size);
    result.check = false;
    return result;
}

int largestBst(Node *root)
{
	return solve(root).size;
}