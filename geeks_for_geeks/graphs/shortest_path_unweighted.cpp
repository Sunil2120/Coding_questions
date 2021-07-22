// Bfs is used to find the shortest path in unweighted graph
#include<bits/stdc++.h>
using namespace std;


void solve(map<int,vector<int>>& adj,int n,int m,int start,int dest)
{
	queue<int> Q;
	vector<bool> visited;
	vector<int> parent;
	visited.assign(n,false);
	parent.assign(n,-1);
	visited[0]=true;
	Q.push(0);
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		// explore it's neighbour
		for(int i=0;i<adj[cur].size();i++)
		{
			int next = adj[cur][i];
			if(visited[next]==true)
			{
				continue;
			}
			parent[next]=cur;
			visited[next]=true;
			Q.push(next);
			if(next==dest)
			{
				break;
			}
		}
	}
	if(!Q.empty())
	{
		cout << -1 << endl;
		return ;
	}
	vector<int> output;
	int temp = dest;
	while(temp!=start)
	{
		output.push_back(temp);
		temp = parent[temp];
	}
	output.push_back(start);
	reverse(output.begin(),output.end());
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " " ;
	}
	cout << endl;
	cout << output.size() -1 << endl;
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
	int source,dest;
	cin >> source >> dest;
	solve(adj,n,m,source,dest);
	return 0;
}