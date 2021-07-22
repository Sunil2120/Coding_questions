#include<bits/stdc++.h>
using namespace std;

int dfs(int** adj,map<int,vector<int>>& adj2,int start,int n,int dest,vector<bool>& visited)
{
	if(start==dest)
	{
		return 0;
	}
	visited[start]=true;
	int count;
	int min_count = 100000;
	// neighbours
	for(int i=0;i<adj2[start].size();i++)
	{
		count = 0;
		int next = adj2[start][i];
		if(visited[next]==false)
		{
			if(adj[start][next]!=1)
			{
				// we have reverse this
				count+=1;
			}
			count+=dfs(adj,adj2,next,n,dest,visited);
			min_count = min(min_count,count);
		}
	}
	visited[start]=false;
	return min_count;
}

int solve(int** adj,map<int,vector<int>>& adj2,int n,int m,int src,int dest)
{
	vector<bool> visited(n,false);
	return dfs(adj,adj2,src,n,dest,visited);

}

int main()
{
	int n;
	cin >> n;
	int** adj = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			adj[i][j]=INT_MAX;
		}
	}
	int m;
	cin >> m;
	map<int,vector<int>> adj2;
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj2[f].push_back(s);
		adj2[s].push_back(f);
		adj[f][s]=1;
	}
	int src,dest;
	cin >> src >> dest;
	cout << solve(adj,adj2,n,m,src,dest) << endl;
	return 0;
}