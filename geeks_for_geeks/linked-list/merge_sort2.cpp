
Node* getmid(Node* head,Node* tail)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* s=head;
    Node* f = head;
    while(f!=tail && f->next!=tail)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

Node* merge(Node* first,Node* second)
{
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }
    Node* result = NULL;
    if(first->data <= second->data)
    {
        result = first;
        result->next = merge(first->next,second);
    }
    else
    {
        result = second;
        result->next = merge(first,second->next);
    }
    return result;
}

Node* mergesort(Node* head,Node* tail)
{
    if(head==tail)
    {
        Node* temp = new Node(head->data);
        return temp;
    }
    Node* mid = getmid( head, tail);
    Node* first = mergesort(head,mid);
    Node* second = mergesort(mid->next,tail);
    head = merge(first,second);
    return head;
}

Node* mergeSort(Node* head) {
    
    Node* cur = head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    return mergesort(head,cur);
}