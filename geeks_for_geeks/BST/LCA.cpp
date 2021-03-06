Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL)
   {
       return root;
   }
   if(root->data==n1 || root->data==n2)
   {
       return root;
   }
   if(n1 <= root->data && n2 <= root->data)//left
   {
       return LCA(root->left,n1,n2);
   }
   if(n1> root->data && n2 > root->data)// both are present in right
   {
       return LCA(root->right,n1,n2);
   }
   return root;
}