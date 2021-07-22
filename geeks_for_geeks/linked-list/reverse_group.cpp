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

Node* reverse_groups(Node* head,int k)
{
	if(head==NULL || k==0 || k==1)
	{
		return head;
	}
	Node* cur = head;
	Node* prev = NULL;
	int count = 0;
	while(count!=k && cur!=NULL)
	{
		prev = cur;
		Node* temp = cur->next;
		cur->next = cur->prev;
		cur->prev=temp;
		cur = temp;
		count+=1;
	}
	prev->prev=NULL;
	if(cur!=NULL)
	{
		cout << cur->data << endl;
	}
	head->next = reverse_groups(cur,k);
	return prev;




}

Node* reverse_group(Node* head,int k)
{
	vector<Node*> stack;
	if(head==NULL)
	{
		return NULL;
	}
	Node* cur = head;
	int count = 0;
	while(cur!=NULL)
	{
		while(count!=k && cur!=NULL)
		{
			stack.push_back(cur);
			cur=cur->next;
			count+=1;
		}
		Node* temp = stack.back();
		Node* cur1 = temp;
		stack.pop_back();
		count-=1;
		while(count-- && stack.size()!=0)
		{
			cur1->next = stack.back();
			cur1 = cur1->next;
			stack.pop_back();
		}
		cur1->next=NULL;
		stack.push_back(temp);
		count = 0;
	}
	head = stack[0];
	cur = head;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	for(int i=1;i<stack.size();i++)
	{
		cur->next = stack[i];
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
	}
	return head;
}

int main()
{
	int n,k;
	cin >> n >> k;
	Node* head = NULL;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		head = insert(head,val);
	}

	head = reverse_group(head,k);
	Node* cur = head;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
	return 0;
}