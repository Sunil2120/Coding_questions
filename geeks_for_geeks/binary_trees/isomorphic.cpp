
//Given two Binary Trees. Check whether they are Isomorphic or not.

// Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
// For example, following two trees are isomorphic with following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
// ISomorphicTrees

bool isIsomorphic(Node *root1,Node *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    // if  just one of them is NULL
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    // if data is not same
    if(root1->data != root2->data)
    {
        return false;
    }
    // check isomorphism
    // case1
    if(isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))
    {
        return true;
    }
    //case 2
    if(isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left))
    {
        return true;
    }
    return false;
}