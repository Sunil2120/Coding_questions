// Euler Circuit : start and end with same vertex and all edges should be visited that too only once and 
// vertices can be visited any number of times
#include<bits/stdc++.h>
using namespace std;

void dfs(map<int,vector<int> >& adj,int start,int n,vector<int>& output)
{
	while(adj[start].size()!=0)
	{
		int next = adj[start].back();
		adj[start].pop_back();
		dfs(adj,next,n,output);
	}
	output.push_back(start);
	return ;
}

void solve(map<int,vector<int> >& adj,int n,int m)
{
	vector<int> output;
	dfs(adj,0,n,output);
	while(output.size()!=0)
	{
		cout << output.back() << " ";
		output.pop_back();
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
		adj[f].push_back(s);// directed graph
	}
	solve(adj,n,m);
}