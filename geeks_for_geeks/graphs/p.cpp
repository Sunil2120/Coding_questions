#include<bits/stdc++.h>
using namespace std;



void dfs(unordered_map<int,vector<int>>& adj,int start,int parent,vector<bool>& visited,vector<bool>& articulation,int& timer,vector<int>& In,vector<int>& Low)
{
	visited[start]=true;
	In[start]=timer;
	Low[start]=timer;
	timer+=1;
	int children = 0;
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(parent==next)
		{
			continue;
		}
		if(visited[next]==true)//backedge
		{
			Low[start]=min(Low[start],In[next]);
		}
		else
		{
			children+=1;
			dfs(adj,next,start,visited,articulation,timer,In,Low);
			Low[start]=min(Low[start],Low[next]);
			if(parent!=-1 && Low[next] >= In[start])//non-root articulation
			{
				articulation[start]=true;
			}
		}
	}
	if(children > 1 && parent==-1)// children > 1 and root node
	{
		articulation[start]=true;
	}
	return ;

}
void solve(unordered_map<int,vector<int>>& adj,int n)
{
	vector<bool> visited(n,false);
	vector<bool> articulation(n,false);
	vector<int> In(n,-1);
	vector<int> Low(n,-1);
	int timer = 1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,-1,visited,articulation,timer,In,Low);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(articulation[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
	return ;
}
int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	unordered_map<int,vector<int>> adj;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve(adj,n);
	return 0;
}