#include<bits/stdc++.h>
using namespace std;

// refer CP algorithms
// directed graph

bool dfs(map<int,vector<int>>& adj,int start,vector<int>& color,int& cycle_start,int& cycle_end,vector<int>& parent)
{
	color[start]=1;
	// exploring it's neighbours
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(color[next]==0)
		{
			parent[next]=start;
			bool temp = dfs(adj,next,color,cycle_start,cycle_end,parent);
			if(temp==true)
			{
				return true;
			}
		}
		if(color[next]==1)
		{
			// we got a cylce
			cycle_start = next;
			cycle_end = start;
			return true;
		}
	}
	color[start]=2;
	return false;
}

void solve(map<int,vector<int>>& adj,int n,int m)
{
	vector<int> color;
	vector<int> output;
	vector<int> parent;
	int cycle_start = -1;
	int cylce_end = -1;
	color.assign(n,0);
	parent.assign(n,-1);
	// 0 not yet visited
	// 1 just visited
	// 2 all it's neighbours are explored
	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
		{
			bool temp = dfs(adj,i,color,cycle_start,cylce_end,parent);
			if(temp==true)
			{
				break;
			}
		}
	}
	if(cycle_start==-1)
	{
		cout << "Acyclic" << endl;
		return ;
	}
	output.push_back(cycle_start);
	for(int i=cylce_end;i!=cycle_start;i=parent[i])
	{
		output.push_back(i);
	}
	output.push_back(cycle_start);
	reverse(output.begin(),output.end());
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return ;
}

int main()
{
	int n,m;
	cin >> n >> m;
	map<int,vector<int>> adj;
	// directed
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
	}
	solve(adj,n,m);
}