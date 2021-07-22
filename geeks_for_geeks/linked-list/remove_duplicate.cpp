##include<bits/stdc++.h>
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

Node* removeduplicate(Node* head)
{
	if(head==NULL)
	{
		return head;
	}
	Node* cur = head->next;
	Node* prev = head;
	while(cur!=NULL)
	{
		if(prev->data == cur->data)
		{
			prev->next = cur->next;
			cur->next = NULL;
			cur = prev->next;
			continue;
		}
		prev=prev->next;
		cur=cur->next;
	}
	return head;
}

int main()
{
	int n;
	cin >> n;
	return 0;
}