#include<bits/stdc++.h>
using namespace std;


void getparent(int* parent,int index)
{
	if(parent[index]==-1)
	{
		cout << index << endl;
		return ;
	}
	cout << index << " ";
	getparent(parent,parent[index]);
}


bool dfs(map<int,vector<int>>& adj,int start,vector<bool>& visited,int n,int* parent)
{
	visited[start]=true;
	// check whether everything is visited or not
	int check = 0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			check = 1;
			break;
		}
	}
	if(check == 0)
	{
		// we will check whether there is edge from start to source(0)
		for(int i=0;i<adj[start].size();i++)
		{
			if(adj[start][i]==0)
			{
				getparent(parent,start);
				return true;
			}
		}
		visited[start]=false;
		return false;
	}
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(visited[next]==false)
		{
			parent[next]=start;
			bool temp = dfs(adj,next,visited,n,parent);
			if(temp)
			{
				return true;
			}
		}
	}
	visited[start]=false;
	return false;

}

bool solve(map<int,vector<int>>& adj,int n,int e)
{
	vector<bool> visited;
	int* parent = new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=0;
	}
	visited.assign(n,false);
	int src = 0;
	parent[0]=-1;
	bool ans= dfs(adj,0,visited,n,parent);
	return ans;
}

int main()
{
	int n,e;
	cin >> n >> e;
	map<int,vector<int>> adj;
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);// undirected graph
		adj[s].push_back(f);
	}
	cout << solve(adj,n,e) << endl;
	return 0;
}