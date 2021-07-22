#include<bits/stdc++.h>
using namespace std;


int dfs(map<int,vector<int>>& adj,int start,bool* visited,int& ans)
{
	visited[start]=true;
	int nd = 0;
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(visited[next]==false)
		{
			int n = dfs(adj,next,visited,ans);
			// if this subbranch has even no of nodes we wont consider it to count the number of nodes
			// to avoid overlapping
			if((n%2)==0)// this have even number of nodes 
			{
				ans=ans+1;
			}
			else
			{
				nd+=n;
			}
		}
	}
	return nd+1;// including parent node
}


int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	map<int,vector<int>> adj;
	for(int i=0;i<e-1;i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	bool* visited = new bool[e]();
	int ans = 0;
	int value = dfs(adj,0,visited,ans);
	if((value%2)==0)//even
	{
		ans+=1;
	}
	// in family there are n number of people
	// in graph containing m number of nodes
	// it can be divided into ans number of subbranches containing even-nodes
	// in 1 packet we can give to ans no of people
	// for n number of people how much we need
	// required = (n*1)/ans;
	int total = (n/ans);
	if((n%ans)!=0)
	{
		total+=1;// since it has remainder we need extra packet
	}
	cout << total << endl;
	return 0;
}