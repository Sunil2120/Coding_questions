#include<bits/stdc++.h>
using namespace std;



void dfs(int** adj,int start,vector<bool>& visited,int n,vector<int>& order)
{
	visited[start]=true;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==true || i==start || adj[start][i]==INT_MAX)
		{
			continue;
		}
		dfs(adj,i,visited,n,order);
	}
	order.push_back(start);
	return ;
}
void solve(int** adj,int n,int src)
{
	//get the topological sorting
	vector<int> order;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,visited,n,order);
		}
	}
	
	reverse(order.begin(),order.end());
	vector<int> dist(n,INT_MIN);
	dist[src]=0;
	for(int i=0;i<order.size();i++)
	{
		int cur = order[i];
		for(int j=0;j<n;j++)
		{
			if(j!=cur && adj[cur][j]!=INT_MAX)
			{
				if(dist[cur]!=INT_MIN && (dist[j] < dist[cur]+adj[cur][j]))
				{
					dist[j]=dist[cur]+adj[cur][j];
				}
			}
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
	int n;
	cin >> n;
	int e;
	cin >> e;
	int** adj = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			adj[i][j]=INT_MAX;
		}
	}
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u][v]=w;
	}
	int src ;
	cin >> src;
	
	solve(adj,n,src);
	return 0;
}