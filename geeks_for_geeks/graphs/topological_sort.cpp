#include<bits/stdc++.h>
using namespace std;

// topological sorting - ordering of vertices such that u always comes before v in the ordering if u -> v.
// time O(V+E) and O(V) auxillary space
void dfs(map<int,vector<int>>& adj,int start,vector<int>& stack,vector<bool>& visited)
{
	visited[start]=true;
	// explore it's indegree
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(visited[next]==true)
		{
			continue;
		}
		dfs(adj,next,stack,visited);
	}
	// all it's indegree are pushed on to the stack
	stack.push_back(start);
	return ;
}

void solve(map<int,vector<int> >& adj,int n,int m)
{
	vector<bool> visited;
	vector<int> stack;
	visited.assign(n,false);
	// given graph can be disconnected
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,stack,visited);
		}
	}

	while(stack.size()!=0)
	{
		cout << stack.back() << " ";
		stack.pop_back();
	}
	cout << endl;
	return ;
}
int main()
{
	int n,m;
	cin >> n >> m;
	map<int,vector<int> > adj;
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
	}
	solve(adj,n,m);
	return 0;
}