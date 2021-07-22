// Articulation_points(cut vertex) on removing which number of connected components increases.
#include<bits/stdc++.h>
using namespace std;

// O(V+E) time complexity

void dfs(map<int,vector<int>>& adj,int start,int parent,vector<bool>& visited,vector<int>& In,vector<int>& Low,int& timer)
{
	visited[start]=true;
	In[start]=Low[start]=timer++;
	int children = 0;
	// exploring it's neighbours
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(next==parent)
		{
			continue;
		}
		if(visited[next]==true)// backedge to ancestor
		{
			// minimize the low
			Low[start]=min(Low[start],In[next]);
		}
		else
		{
			children+=1;
			dfs(adj,next,start,visited,In,Low,timer);
			Low[start]=min(Low[start],Low[next]);
			if(Low[next] >= In[start] && parent!=-1)// adj vertex have no backedge and cur node is not root
			{
				cout << start << endl;
			}
		}
	}
	if(parent==-1 && children > 1)// root and has atleast 2 children
	{
		cout << start << endl;
	}
	return ;
}

void solve(map<int,vector<int>>& adj,int n,int m)
{
	vector<bool> visited;
	vector<int> In;
	vector<int> Low;
	visited.assign(n,false);
	In.assign(n,-1);
	Low.assign(n,-1);
	int timer = 0;
	// given graph can be disconnected
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,-1,visited,In,Low,timer);
		}
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
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