#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* link=NULL;
};
typedef struct node node;


int main()
{
	int n;
	cin >> n;
	vector<int> input;
	node* root = NULL;
	node* temp = new node();
	cin >> temp->data;
	root = temp;
	node* prev = temp;
	input.push_back(temp->data);
	for(int i=1;i<n;i++)
	{
		node* temp = new node();
		cin >> temp->data;
		input.push_back(temp->data);
		prev->link=temp;
		prev=prev->link;
	}
	node* cur = root;
	while(cur!=NULL)
	{
		cout << cur->data << " ";
		cur = cur->link;
	}
	cout << endl;
	if(root==NULL)
	{
		cout << "nothing" << endl;
		return 0;
	}
	if(root->link==NULL)
	{
		cout << root->data << endl;
		return 0;
	}
	cur = root->link;
	while(cur!=NULL && cur->link!=NULL)
	{
		cur->data = input.back();
		input.pop_back();
		cur=cur->link->link;
	}
	if(cur!=NULL)
	{
		cur->data = input.back();
		input.pop_back();
	}
	reverse(input.begin(),input.end());
	cur = root;
	while(cur!=NULL && cur->link!=NULL)
	{
		cur->data = input.back();
		input.pop_back();
		cur=cur->link->link;
	}
	if(cur!=NULL)
	{
		cur->data = input.back();
		input.pop_back();
	}
	node* t = root;
	while(t!=NULL)
	{
		cout << t->data << " ";
		t=t->link;
	}
	cout << endl;

	
	return 0;
}