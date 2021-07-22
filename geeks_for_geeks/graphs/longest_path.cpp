// Longest path in DAG using topological order
#include<bits/stdc++.h>
using namespace std;

void dfs(map<int,vector<pair<int,int>>>& adj,int start,vector<bool>& visited,vector<int>& stack)
{
	visited[start]=true;
	// explore it's neighbours
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i].first;
		if(visited[next]==false)
		{
			dfs(adj,next,visited,stack);
		}
	}
	stack.push_back(start);
	return ;
}

void solve(map<int,vector<pair<int,int>>>& adj,int n,int e)
{
	int src = 0;
	vector<int> dist;
	dist.assign(n,INT_MAX);
	dist[src]=0;
	vector<int> stack;
	vector<bool> visited;
	visited.assign(n,false);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,visited,stack);
		}
	}
	// we got the topological order
	while(stack.size()!=0)
	{
		int cur = stack.back();// we have already updated cur because it's in topological order
		stack.pop_back();
		if(dist[cur]!=INT_MAX)
		{
			// explore it's neighbours
			for(int i=0;i<adj[cur].size();i++)
			{
				int next = adj[cur][i].first;
				if(dist[next] > dist[cur]+adj[cur][i].second)
				{
					dist[next]=dist[cur]+adj[cur][i].second;
				}
			}
		}
	}

	// we will negate the dist
	for(int i=0;i<n;i++)
	{
		dist[i]=-1*dist[i];
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
	int  n,e;
	cin >> n >> e;
	map<int,vector<pair<int,int>>> adj;
	for(int i=0;i<e;i++)
	{
		int f,s,w;
		cin >> f >> s >> w;
		w  = -1*w;
		adj[f].push_back(make_pair(s,w));// direct
	}
	solve(adj,n,e);
}