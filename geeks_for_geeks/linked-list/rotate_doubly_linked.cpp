#include<iostream>
using namespace std;



struct node
{
	int data;
	struct node* next = NULL;
	struct node* prev = NULL;
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
		head=newnode(key);
		return head;
	}
	Node* cur=head;
	Node* prev = NULL;
	while(cur->next!=NULL)
	{
		prev=cur;
		cur=cur->next;
	}
	Node* temp = newnode(key);
	cur->next = temp;
	temp->prev=cur;
	return head;
}

Node* solve(Node* head,int k)
{
	if(k==0)
	{
		return head;
	}
	if(head==NULL)
	{
		return head;
	}
	Node* cur = head;
	Node* last = head;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next = cur;
	cur->prev = last;
	Node* prev = NULL;
	while(k--)
	{
		prev = cur;
		cur=cur->next;
	}
	prev->next = NULL;
	cur->prev = NULL;
	head=cur;
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
	
	Node* temp = reverse_groups(cur,k);
	head->next = temp;
	if(temp!=NULL)
	{
		temp->prev = head;
	}
	
	
	return prev;




}

int main()
{
	int n;
	cin >> n;
	Node* head = NULL;
	while(n--)
	{
		int key;
		cin >> key;
		head = insert(head,key);
	}
	int k;
	cin >> k;
	head = reverse_groups(head,k);
	Node* cur = head;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
		cur=cur->next;
	}
	cout << endl;
	return 0;
}