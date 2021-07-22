#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next=NULL;
};


node* newnode(int key)
{

	node* temp = new node();
	temp->data = key;
	return temp;
}

node* insert(node* head,int key)
{
	node* temp = newnode(key);
	if(head==NULL)
	{
		head = temp;
		return head;
	}
	node* cur = head;
	while(cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = temp;
	return head;
}

node* reverse_list(node* head)
{
	node* cur = NULL;
	node* prev = NULL;
	node* next = NULL;
	if(head==NULL)
	{
		return head;
	}
	cur = head;
	if(cur!=NULL)
	{
		next = cur->next;
	}
	while(next!=NULL)
	{
		cur->next = prev;
		prev=cur;
		cur=next;
		next=next->next;
	}
	cur->next = prev;
	head = cur;
	return head;
}

// using stacks
node* reverse2(node* head)
{
	vector<node*> stack;
	if(head==NULL)
	{
		return head;
	}
	node* cur = head;
	stack.push_back(cur);
	cur = cur->next;
	while(cur!=NULL)
	{
		stack.push_back(cur);
		cur=cur->next;
	}
	head = stack.back();
	stack.pop_back();
	cur = head;
	while(stack.size()!=0)
	{
		cur->next = stack.back();
		stack.pop_back();
		cur=cur->next;
		cur->next = NULL;
	}
	return head;

}
int main()
{
	int n;
	cin >> n;
	node* head = NULL;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		head = insert(head,val);
	}
	head = reverse2(head);
	node* cur = head;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;

	return 0;
}