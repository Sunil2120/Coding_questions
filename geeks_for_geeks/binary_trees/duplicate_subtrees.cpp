string inorder(Node* root,unordered_map<string,int>& hash,vector<int>& output)
{
    if(root==NULL)
    {
        return "";
    }
    string str = "(";
    str += inorder(root->left,hash,output);
    str+= (root->data + '0');
    str+= inorder(root->right,hash,output);
    str+=")";
    if(hash[str]==1)//duplicate
    {
        output.push_back(root->data);//cur subtree is a duplicate
    }
    hash[str]+=1;
    return str;
}
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
void printAllDups(Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    unordered_map<string,int> hash;
    vector<int> output;
    inorder(root,hash,output);
    if(output.size()==0)
    {
        cout << -1 << " ";
        return ;
    }
    while(!output.empty())
    {
        cout << output.back() << " ";
        output.pop_back();
    }
    return ;
    
}