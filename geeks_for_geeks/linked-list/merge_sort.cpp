#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next=NULL;
};

typedef struct node Node;


Node* newnode(int key)
{

	Node* temp = new node();
	temp->data = key;
	return temp;
}

Node* insert(Node* head,int key)
{
	Node* temp = newnode(key);
	if(head==NULL)
	{
		head = temp;
		return head;
	}
	Node* cur = head;
	while(cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = temp;
	return head;
}
void getmid(Node* head,Node* a,Node* b)
{
	if(head==NULL)
	{
		return;
	}
	Node* sl = head;
	Node* fl = head->next;
	while(fl!=NULL)
	{
		fl = fl->next;
		if(fl->next!=NULL)
		{
			sl=sl->next;
			fl=fl->next;
		}
	}
	a = head;
	b =sl->next;
	return ;
}


Node* sort_linked(Node* head,Node* a,Node* b)
{
	if(head==NULL)
	{
		return head;
	}
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	Node* result ;
	
	if(a->data <= b->data)
	{
		result = a;
		result->next = sort_linked(head,a->next,b);
	}
	else
	{
		result = b;
		result->next = sort_linked(head,a,b->next);
	}
	return result;

}


void merge_sort(Node* head)
{
	if(head==NULL)
	{
		return ;
	}
	if(head->next==NULL)
	{
		return;
	}
	Node* a;
	Node* b;
	getmid(head,a,b);
	merge_sort(a);
	merge_sort(b);
	head = sort_linked(head,a,b);
	return ;
	
}

int main()
{
	int n;
	cin >> n;
	Node* head = NULL;
	for(int i=0;i<n;i++)
	{
		int value;
		cin >> value;
		head = insert(head,value);
	}

	merge_sort(head);
	Node* cur = head;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
	}
	cout << endl;
	return 0;
	return 0;
}