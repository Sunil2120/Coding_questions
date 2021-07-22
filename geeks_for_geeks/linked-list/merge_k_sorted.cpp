/*
time O(nklog(k)) and space O(1)
Node* merge(Node* a,Node* b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    Node* result = NULL;
    if(a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next,b);
    }
    else
    {
        result = b;
        result->next = merge(a,b->next);
    }
    return result;
}
 arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  
Node * mergeKLists(Node *arr[], int N)
{
       if(N==0)
       {
           return NULL;
       }
       if(N==1)
       {
           return arr[0];
       }
       for(int i=1;i<N;i++)
       {
           arr[0]=merge(arr[0],arr[i]);
       }
       return arr[0];
}*/
