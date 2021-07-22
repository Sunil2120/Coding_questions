#include<bits/stdc++.h>
using namespace std;

// O(V+E) time complexity


void dfs(map<int,vector<int>>& adj,int start,int parent,vector<bool>& visited,vector<int>& In,vector<int>& Low,int& timer)
{
	visited[start]=true;
	In[start]=Low[start]=timer++;
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(next==parent)
		{
			continue;
		}
		if(visited[next]==true)// backedge
		{
			//minimize the Low
			Low[start]=min(Low[start],In[next]);
		}
		else
		{
			dfs(adj,next,start,visited,In,Low,timer);
			Low[start]=min(Low[start],Low[next]);
			if(Low[next] > In[start])
			{
				// it is a bridge
				cout << start << "---->" << next << endl;
			}
		}
	}
	return ;
}

void solve(map<int,vector<int>>& adj,int n,int m)
{
	vector<bool> visited;
	vector<int> In;
	vector<int> Low;
	int timer = 0;
	visited.assign(n,false);
	In.assign(n,-1);
	Low.assign(n,-1);
	// graph can be disconnected
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,-1,visited,In,Low,timer);
		}
	}
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
		adj[s].push_back(f);
	}
	solve(adj,n,m);
	return 0;
}