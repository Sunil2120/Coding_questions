

Node* solve(Node* head)
{
	if(head==NULL)
	{
		return head;
	}
	Node* cur = head;
	Node* prev=NULL;
	while(cur->next!=NULL)
	{
		prev=cur;
		cur=cur->next;
	}
	cur->next=head;
	head=cur;
	prev->next=NULL;
	return head;
}