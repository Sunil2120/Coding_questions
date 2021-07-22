Node *copyList(Node *head) {
    
    unordered_map<Node*,Node*> hash;
    Node* cur = head;
    if(head==NULL)
    {
        return NULL;
    }
    while(cur!=NULL)
    {
        hash[cur]=getnode(cur->data);
        cur=cur->next;
    }
    cur = head;
    while(cur!=NULL)
    {
        hash[cur]->arb = hash[cur->arb];
        hash[cur]->next = hash[cur->next];
        cur=cur->next;
    }
    Node* head2 = hash[head];
    return head2;
    
}