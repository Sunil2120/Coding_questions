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
	Node* slow = head;
	Node* fast = head;
	if(head==NULL)
	{
		return NULL;
	}
	do
	{
		slow = slow->next;
		if(fast->next!=NULL && fast->next->next!=NULL)
		{
			fast = fast->next->next;
		}
		else
		{
			fast=NULL;
		}
	}while(slow!=fast && slow!=NULL && fast!=NULL);
	if(slow==fast)
	{
		cout << "Yes" << endl;
		slow = head;
		while(slow!=fast)
		{
			slow=slow->next;
			fast = fast->next;
		}
		return slow;
	}
	cout << "NO" << endl;
	return head;

}
int main()
{
	int n;

}