// detecting negative weight cycle both in connected and disconnected graphs
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y,w;
};

bool solve(vector<node*>& edges,int src,int n,int m,vector<int>& dist)
{
	
	dist[src]=0;
	// do this for n-1 times
	for(int i=1;i<=(n-1);i++)
	{
		for(int j=0;j<m;j++)
		{
			int u = edges[j]->x;
			int v = edges[j]->y;
			int w = edges[j]->w;
			if( dist[u]!=INT_MAX && dist[v] > dist[u]+w)
			{
				dist[v]=dist[u]+w;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
			int u = edges[j]->x;
			int v = edges[j]->y;
			int w = edges[j]->w;
			if( dist[u]!=INT_MAX && dist[v] > dist[u]+w)
			{
				return true;
			}
	}
	
	return false;
}

bool solve2(vector<node*> edges,int n,int m)
{
	vector<int> dist;
	dist.assign(n,INT_MAX);
	for(int i=0;i<n;i++)
	{
		if(dist[i]==INT_MAX)
		{
			bool temp = solve(edges,i,n,m,dist);
			if(temp==true)
			{
				return true;
			}
		}
	}
	return false;

}




int main()
{
	int n,m;
	cin >> n >> m;
	vector<node*> edges;
	for(int i=0;i<m;i++)
	{
		node* temp = new node();
		cin >> temp->x >> temp->y >> temp->w;
		edges.push_back(temp);
	}
	cout << solve2(edges,n,m) << endl;
}