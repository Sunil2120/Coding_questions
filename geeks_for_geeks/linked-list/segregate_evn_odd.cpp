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

Node* solve(Node* head)
{
	
	if(head==NULL)
	{
		return head;
	}
	if(head->next==NULL)
	{
		return head;
	}
	Node* cur = head;
	Node* odd = NULL;
	Node* even = NULL;
	Node* cur1 = NULL;
	Node* cur2 = NULL;
	int count = 0;
	while(cur!=NULL)
	{
		cur=cur->next;
		count+=1;
	}
	cur = head;
	while(count-- && cur!=NULL)
	{
		Node* next = cur->next;
		if(cur->data%2 != 0)
		{
			if(cur1==NULL)
			{
				cur->next = NULL;
				cur1 = cur;
				odd = cur1;
			}
			else
			{
				cur->next = NULL;
				cur1->next = cur;
				cur1=cur1->next;
			}
		}
		else
		{
			if(cur2==NULL)
			{
				cur->next = NULL;
				cur2 = cur;
				even = cur2;
			}
			else
			{
				cur->next = NULL;
				cur2->next = cur;
				cur2=cur2->next;
			}
		}
		cur=next;
	}
	if(odd==NULL)
	{
		return even;
	}
	if(even == NULL)
	{
		return odd;
	}
	cur2->next = odd;
	return even;
}
int main()
{
	int n;
	cin >> n;
	Node* head = NULL;
	while(n--)
	{
		int val;
		cin >> val;
		head = insert(head,val);
	}
	head = solve(head);
	Node* cur = head;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
		cur=cur->next;
	}
	cout << endl;
	return 0;
}