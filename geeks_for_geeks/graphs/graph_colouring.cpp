// graph colouring using Greedy Algorithm
#include<bits/stdc++.h>
using namespace std;


void solve(map<int,vector<int>>& adj,int n,int e)
{

	vector<int> color(n,-1);
	color[0]=0;
	for(int i=1;i<n;i++)
	{
		set<int> check;
		int j;
		for(j=0;j<adj[i].size();j++)
		{
			int next = adj[i][j];
			if(color[next]!=-1)
			{
				check.insert(color[next]);
			}
		}
		for(j=0;j<n;j++)
		{
			if(check.find(j)==check.end())
			{
				color[i]=j;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << color[i] << " ";
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
	map<int,vector<int>> adj;
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	solve(adj,n,e);
	return 0;
}