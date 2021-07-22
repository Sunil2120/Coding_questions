#include<bits/stdc++.h>
using namespace std;

bool dfs(map<int,vector<pair<int,int>>>& adj,int src,vector<bool>& visited,int k,int cost)
{
	visited[src]=true;
	if(cost >= k)
	{
		return true;
	}
	// explore it's neigbours
	for(int i=0;i<adj[src].size();i++)
	{
		int next = adj[src][i].first;
		int w = adj[src][i].second;
		if(visited[next]==false)
		{
			bool temp = dfs(adj,next,visited,k,cost+w);
			if(temp==true)
			{
				return true;
			}
		}
	}
	visited[src]=false;
	return false;
}

bool solve(map<int,vector<pair<int,int>>>& adj,int src,int n,int e,int k)
{
	vector<bool> visited;
	visited.assign(n,false);
	return dfs(adj,src,visited,k,0);
}



int main()
{
	int n,e;
	cin >> n >> e;
	map<int,vector<pair<int,int>>> adj;
	for(int i=0;i<e;i++)
	{
		int f,s,w;
		cin >> f >> s >> w;
		adj[f].push_back(make_pair(s,w));
		adj[s].push_back(make_pair(f,w));
	}
	int src,k;
	cin >> src >> k;
	cout << solve(adj,src,n,e,k) << endl;
	return 0;
}