#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* next = NULL;
};
typedef struct node Node;


Node* newnode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}

Node* insert(Node* head,int key)
{
	if(head==NULL)
	{
		head = newnode(key);
		head->next = head;
		return head;
	}
	Node* cur = head;
	while(cur->next!=head)
	{
		cur=cur->next;
	}
	Node* temp = newnode(key);
	cur->next = temp;
	temp->next = head;
	return head;
}

Node* delete_node(Node* head,int data)
{

	if(head==NULL)
	{
		return head;
	}
	if(head->data == data)
	{
		Node* last = head;
		while(last->next!=head)
		{
			last = last->next;
		}
		Node* temp = head->next;
		head->next = NULL;
		head=temp;
		last->next = head;
	}
	Node* prev=head;
	Node* cur = head->next;
	while(cur!=head)
	{
		if(cur->data == data)
		{
			prev->next = cur->next;
			cur->next = NULL;
			cur = prev->next;
			continue;
		}
		prev=cur;
		cur=cur->next;
	}
	return head;
}

int main()
{
	Node* head=NULL;
	int n;
	cin >> n;
	while(n--)
	{
		int val;
		cin >> val;
		head = insert(head,val);
	}
	int data;
	cin >> data;
	head = delete_node(head,data);
	Node* cur = head;
	do
	{
		cout << cur->data << " ";
		cur=cur->next;
	}while(cur!=head);
	return 0;
}