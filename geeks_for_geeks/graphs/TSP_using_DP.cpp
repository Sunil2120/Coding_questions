// TSP using dp
// refer coding blocks youtube channel.
#include<bits/stdc++.h>
using namespace std;

int dfs(int** adj,int start,int n,bool* visited)
{
	visited[start]=true;
	int min_cost = INT_MAX;
	int check = 0;
	for(int i=0;i<n;i++)
	{
		if(adj[start][i]!=INT_MAX && visited[i]==false)
		{
			check = 1;
			int temp = dfs(adj,i,n,visited)+adj[start][i];
			min_cost = min(min_cost,temp);
		}
	}
	visited[start]=false;
	if(check==0)//leafnode
	{
		return adj[start][0];
	}
	return min_cost;
}



int solve(int** adj,int n,int e)
{
	int s = 0;
	bool* visited = new bool[n]();
	return dfs(adj,s,n,visited);
}

// using bit masking and dp memorization
int solve2(int** adj,int mask,int start,int n,int** dp)
{
	if(dp[mask][start]!=-1)
	{
		return dp[mask][start];
	}
	mask = mask | (1<<start);
	if(mask==((1<<n)-1))// if all cities are visited
	{
		return adj[start][0];
	}
	
	int min_cost = INT_MAX;
	for(int i=0;i<n;i++)
	{
		// check the i city set or not
		if((mask & (1<<i))==0 && adj[start][i]!=INT_MAX)// not visited and have edge.
		{
			int temp = adj[start][i]+solve2(adj,mask,i,n,dp);
			min_cost = min(min_cost,temp);
		}
	}
	dp[mask][start]=min_cost;
	return min_cost;
}


int main()
{
	int n,e;
	cin >> n >> e;
	int** adj=new int*[n];
	for(int i=0;i<n;i++)
	{
		// complete graph
		adj[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			adj[i][j]=INT_MAX;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s,v;
		cin >> f >> s >> v;
		adj[f][s]=v;
		adj[s][f]=v;
	}
	int** dp = new int*[1<<n];// mask
	for(int i=0;i<(1<<n);i++)
	{
		dp[i]=new int[n];// cities(start)
		for(int j=0;j<n;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout << solve(adj,n,e) << endl;
	cout << solve2(adj,0,0,n,dp) << endl;
	for(int i=0;i<(1<<n);i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}