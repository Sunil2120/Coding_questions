#include<bits/stdc++.h>
using namespace std;


void solve(map<int,vector<int>>& adj,int n,vector<int>& indegree)
{
	queue<int> Q;
	vector<int> output(n);
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			Q.push(i);
			output[i]=1;
		}
	}
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		//explore it's neighbors
		for(int i=0;i<adj[cur].size();i++)
		{
			int next = adj[cur][i];
			indegree[next]-=1;
			if(indegree[next]==0)
			{
				output[next]=output[cur]+1;
				Q.push(next);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return ;
}

int main()
{
	int n,e;
	cin >> n >> e;
	map<int,vector<int>> adj;
	vector<int> indegree(n,0);
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]+=1;
	}
	solve(adj,n,indegree);
	return 0;
}