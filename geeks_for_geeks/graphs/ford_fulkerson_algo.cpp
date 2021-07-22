#include<bits/stdc++.h>
using namespace std;

// refer tushar roy video

bool bfs(int** adj,int src,int dest,int n,int* parent)
{
	queue<int> Q;
	parent[src]=-1;
	set<int> visited;
	visited.insert(src);
	Q.push(src);
	while(Q.size()!=0)
	{
		int cur = Q.front();
		Q.pop();
		for(int i=0;i<n;i++)
		{
			if(adj[cur][i] > 0 && visited.find(i)==visited.end())
			{
				visited.insert(i);
				parent[i]=cur;
				Q.push(i);
				if(i==dest)
				{
					return true;
				}
			}
		}
	}
	return false;
}


int solve(int** adj,int n,int src,int dest)
{
	int max_flow = 0;
	int* parent = new int[n]();
	while(bfs(adj,src,dest,n,parent)==true)
	{
		int min_value = INT_MAX;
		for(int i=dest;i!=src;i=parent[i])
		{
			int u = parent[i];
			int v = i;
			min_value = min(min_value,adj[u][v]);
		}
		// update now
		for(int i=dest;i!=src;i=parent[i])
		{
			int u = parent[i];
			int v = i;
			adj[u][v]-=min_value;
			adj[v][u]+=min_value;
		}
		max_flow+=min_value;
	}
	return max_flow;
}

int main()
{

	int n,m;
	cin >> n >> m;
	int** adj = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n]();
	}
	for(int i=0;i<m;i++)
	{
		int f,s,w;
		cin >> f >> s >> w;
		adj[f][s]+=w;
	}
	int src,dest;
	cin >> src >> dest;
	cout << solve(adj,n,src,dest) << endl;
	return 0;
}