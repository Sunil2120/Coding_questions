int getCount(Node *root, int l, int h)
{
      if(root==NULL)
      {
          return 0;
      }
     
      if(root->data > h)// if root is greater than h all its right will be greater than h
      {
        //left
          return getCount(root->left,l,h);
      }
      else if(root->data < l)// if root is less than l all its left will be lesser than l
      {
        //right
          return getCount(root->right,l,h);
      }
      return getCount(root->left,l,h)+getCount(root->right,l,h)+1;
}