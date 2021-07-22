


/*void solve(Node* head,int data)
{
	if(head==NULL)
	{
		return ;
	}
	Node* cur = head;
	Node* last = head;
	while(last->next!=NULL)
	{
		last = last->next;
	}
	while(cur!=NULL)
	{
		int sum = data - cur->data;
		Node* first = cur->next;
		Node* second = last;
		while(first!=second &&  second->next!=first )
		{
			int sum1 = first->data + second->data;
			if(sum == sum1)
			{
				cout << cur->data << " " << first->data << " " << second->data << endl;
				first=first->next;
				second = second->prev;
			}
			else if(sum1 < sum)
			{
				first=first->next;
			}
			else
			{
				second = second->prev;
			}
		}
		cur=cur->next;
	}
	return ;

}*/