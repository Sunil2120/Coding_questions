#include<bits/stdc++.h>
using namespace std;

struct node
{
	int id;
	int arrival;
	int burst;
};

typedef struct node Node;


struct compare1
{
	bool operator()(Node* a,Node* b)
	{
		return a->arrival > b->arrival;
	}
};

struct compare2
{
	bool operator()(Node* a,Node* b)
	{
		return a->burst > b->burst;
	}
};



void solve(priority_queue<Node*,vector<Node*>,compare1>& Q1,int n)
{
	priority_queue<Node*,vector<Node*>,compare2> Q2;
	Node* first = Q1.top();
	Q1.pop();
	Q2.push(first);
	int time = 0;
	while(!Q2.empty())
	{
		Node* temp = Q2.top();
		Q2.pop();
		cout << temp->id << endl;
		time+=temp->burst;
		while(Q1.size() > 0 && (Q1.top())->arrival <=time)
		{
			//cout << "he" << " " << (Q1.top())->id << endl;
			Q2.push(Q1.top());
			Q1.pop();
		}
		if(Q2.empty() && !Q1.empty())
		{
			Q2.push(Q1.top());
			Q1.pop();
		}
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	priority_queue<Node*,vector<Node*>,compare1> Q1;
	priority_queue<Node*,vector<Node*>,compare2> Q2;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		Node* temp = new Node();
		temp->id = a;
		temp->arrival = b;
		temp->burst = c;
		Q1.push(temp);
	}
	solve(Q1,n);
}