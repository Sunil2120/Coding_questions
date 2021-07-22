
//Duplicate subtree in Binary Tree 

//Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

//Time complexity : inorder traversal O(n)(no of nodes)
// space complexity : hash map O(n)
string inorder(Node* root,unordered_map<string,int>& hash,bool& check)
{
    if(root==NULL)
    {
        return "";
    }
    string str = "(";
    str += inorder(root->left,hash,check);
    str += (root->data + '0');
    str += inorder(root->right,hash,check);
    str +=")";
    if(hash[str]==1)//duplicate
    {
        int len = str.size()-2;//(taking out brackets)
        if(len >=2)
        {
            check = true;
        }
    }
    hash[str]+=1;
    return str;
}

bool dupSub(Node *root)
{
     unordered_map<string,int> hash;
     bool check = false;
     inorder(root,hash,check);
     return check;
}