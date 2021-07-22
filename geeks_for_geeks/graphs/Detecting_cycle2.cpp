#include<bits/stdc++.h>
using namespace std;

bool dfs(map<int,vector<int>>& adj,int start,vector<int>& color,vector<int>& parent,int& cycle_start,int& cycle_end)
{
	color[start]=1;
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(next == parent[start])
		{
			continue;
		}
		if(color[next]==0)//not yet visited
		{
			parent[next]=start;
			bool temp = dfs(adj,next,color,parent,cycle_start,cycle_end);
			if(temp==true)// found a cylce
			{
				return true;
			}
		}
		else if(color[next]==1)
		{
			// found a cycle
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
	vector<int> parent;
	color.assign(n,0);
	parent.assign(n,-1);
	int cycle_start = -1;
	int cycle_end = -1;

	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
		{
			bool temp = dfs(adj,i,color,parent,cycle_start,cycle_end);
			if(temp)
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
	vector<int> output;
	output.push_back(cycle_start);
	for(int i=cycle_end;i!=cycle_start;i=parent[i])
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
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	solve(adj,n,m);
}