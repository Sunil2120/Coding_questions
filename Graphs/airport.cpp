#include<bits/stdc++.h>
using namespace std;

struct node
{
	int src=0;
	int dest=0;
	int weight=0;
};

bool compare(node a,node b)
{
	return a.weight < b.weight;
}

int findparent(int index,int* parent,int n)
{
	if(parent[index]==index)
	{
		return index;
	}
	return findparent(parent[index],parent,n);
}


void solve(node* input,int n,int m,int cost)
{
	long long total = 0;
	sort(input,input+m,compare);
	int* parent = new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	int i=0;
	while(i<m && input[i].weight < cost)
	{
		node cur  = input[i];
		int cur_x = findparent(input[i].src,parent,n);
		int cur_y = findparent(input[i].dest,parent,n);
		if(cur_x!=cur_y)
		{
			total+=cur.weight;
			parent[cur_x]=cur_y;
		}
		i++;
	}

	for(int i=0;i<n;i++)
	{
		if(parent[i]==i)
		{
			total += cost;
		}
	}
	cout << total << endl;
	delete[] parent;
	return ;

}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,cost;
		cin >> n >> m >> cost;
		node* input = new node[m];
		for(int i=0;i<m;i++)
		{
			int start,end,w;
			cin >> start >> end >> w;
			input[i].src = start-1;
			input[i].dest = end-1;
			input[i].weight = w;
		}
		solve(input,n,m,cost);
		delete[] input;
	}
}