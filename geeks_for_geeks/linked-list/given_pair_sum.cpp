

/*
void solve(Node* head,int data)
{
	if(head==NULL)
	{
		return ;
	}
	Node* first = head;
	Node* last = head;
	while(last->next!=NULL)
	{
		last = last->next;
	}
	while(first!=last && last->next!=first)
	{
		int sum = first->data + last->data;
		if(sum == data)
		{
			cout << first->data << " " << last->data << endl;
			first = first->next;
			last = last->prev;
		}
		else if(sum < data)
		{
			first=first->next;
		}
		else
		{
			last = last->prev;
		}
	}
	return ;
}*/