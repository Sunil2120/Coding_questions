#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	struct node* next;
};
typedef struct node node;


node* reverse(node* root)
{
	if(root==NULL || root->next==NULL)
	{
		return root;
	}
	node* prev = root;
	node* cur = NULL;
	node* last = NULL;
	if(prev!=NULL && prev->next!=NULL)
	{
		cur = prev->next;
	}
	if(cur!=NULL && cur->next!=NULL)
	{
		last = cur->next;
	}
	while(last!=NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = last;
		last = last->next;
	}
	cur->next = prev;
	prev=cur;
	cur=NULL;
	root->next = NULL;
	root=prev;
	return root;
}

int main()
{
	int n;
	cin >> n;
	node* root = NULL;
	node* cur = NULL;
	for(int i=0;i<n;i++)
	{
		node* temp = new node();
		cin >> temp->val;
		if(root==NULL)
		{
			root=temp;
			cur = temp;
		}
		else
		{
			cur->next = temp;
			cur=cur->next;
		}
	}
	if(root==NULL || root->next==NULL)
	{
		return ;
	}
	node* t = root;
	int total = n/2;
	int count = 0;
	while(t!=NULL)
	{
		count+=1;
		if(count==total)
		{
			break;
		}
		t = t->next;
	}
	node* root2 = t->next;
	t->next = NULL;
	root2= reverse(root2);
	node* root3 = NULL;
	node* temp1 = root;
	node* temp2 = root2;
	cur = root3;
	while(temp1!=NULL && temp2!=NULL)
	{
		cout << temp1->val << " " << temp2->val << endl;
		node* first = temp1;
		node* second = temp2;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if(root3==NULL)
		{
			root3 = first;
			root3->next = second;
			cur = second;
		
		}
		else
		{
			cur->next = first;
			cur=cur->next;
			cur->next = second;
			cur = cur->next;
		}
	
		
	}
	while(temp1!=NULL)
	{
		cur->next = temp1;
		temp1= temp1->next;
		cur = cur->next;
	}
	while(temp2!=NULL)
	{
		cur->next = temp2;
		temp2= temp2->next;
		cur = cur->next;
	}
	root = root3;
	t = root;
	while(t!=NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}
	cout << endl;
	return 0;


}