// for undirected graph
#include<bits/stdc++.h>
using namespace std;

// this article, BFS based solution is discussed. We do a BFS traversal of the given graph.
//  For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited 
//  and u is not parent of v, 
//  then there is a cycle in graph. 
//  If we don’t find such an adjacent for any vertex, we say that there is no cycle. 
// The assumption of this approach is that there are no parallel edges between any two vertices.
// time O(V+E)

bool solve(map<int,vector<int>>& adj,int n,int m)
{
	vector<int> parent;
	vector<bool> visited;
	queue<int> Q;
	Q.push(0);
	parent.assign(n,-1);
	visited.assign(n,false);
	visited[0]=true;
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		// explore it's neighbours
		for(int i=0;i<adj[cur].size();i++)
		{
			int next = adj[cur][i];
			if(next==parent[cur])
			{
				continue;
			}
			if(visited[next]==true)// already visited
			{
				return true;
			}
			visited[next]=true;
			parent[next]=cur;
			Q.push(next);
		}
	}
	return false;
}


int main()
{
	int n,m;
	cin >> n >> m;
	map<int,vector<int>> adj;
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	cout << solve(adj,n,m) << endl;
}