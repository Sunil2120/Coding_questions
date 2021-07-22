// Bellman ford algorithm
// if a graph is undirected and it has any negative weight edge we can't do anything
// if a graph is undirected and it has no negative weight edges we should use Dijsktra since it's time is less
// if a graph is directed and it  has any negative weight edge we should use Bellman ford
// if a grpah is directed and it has no negative edges we should use Dijstra(time is less).

// time complexity O((V-1)*E)
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y,cost;
};


void solve(vector<node*>& edges,int n,int m)
{
	int check = -1;
	vector<int> dist;
	dist.assign(n,INT_MAX);
	dist[0]=0;// source to source
	// we will do this for v-1 times
	int i;
	for(i=1;i<=n-1;i++)
	{
		if(check==0)
		{
			break;
		}
		check = 0;
		// explore it's edges
		for(int j=0;j<m;j++)
		{
			// edge for u - > v
			int u = edges[j]->x;
			int v = edges[j]->y;
			int w = edges[j]->cost;
			if(dist[u]!=INT_MAX && dist[v] > dist[u]+w)
			{
				check = 1;
				dist[v]=dist[u]+w;
			}
		}
	}
	if(i==n-1)// check for negative weight cylce
	{
		check = 0;
		for(int j=0;j<m;j++)
		{
			int u = edges[j]->x;
			int v = edges[j]->y;
			int w = edges[j]->cost;
			if(dist[v] > dist[u]+w)
			{
				check = 1;
				dist[v]=dist[u]+w;
			} 
		}
		if(check == 1)
		{
			cout << "negative cycle" << endl;
			return ;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << dist[i] << " ";
	}
	cout << endl;
	return ;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<node*> edges; 
	for(int i=0;i<m;i++)
	{
		int f,s,w;
		cin >> f >> s >> w;
		node* temp = new node();
		temp->x = f;
		temp->y = s;
		temp->cost = w;
		edges.push_back(temp);
	}
	solve(edges,n,m);
	return 0;
}