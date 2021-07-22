#include<bits/stdc++.h>
using namespace std;

void solve(map<int,vector<int>>& adj,int n,vector<pair<int,int>>& edges,int m)
{
	set<int> output;
	for(int i=0;i<m;i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;
		int u_count = adj[u].size();
		int v_count = adj[v].size();
		if(output.find(u)!=output.end() || output.find(v)!=output.end())
		{
			continue;
		}
		if(u_count > v_count)
		{
			output.insert(u);
		}
		else
		{
			output.insert(v);
		}
		
	}
	set<int> :: iterator it;
	for(it=output.begin();it!=output.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return ;
}

int main()
{
	int n,m;
	cin >> n >> m;
	map<int,vector<int>> adj;
	vector<pair<int,int>> edges;
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
		edges.push_back(make_pair(f,s));
	}
	solve(adj,n,edges,m);
	return 0;
}