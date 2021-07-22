#include<bits/stdc++.h>
using namespace std;

int dfs(int** adj,int start,int n,vector<bool>& visited)
{
	visited[start]=true;
	int cost = INT_MAX;
	int check = 0;
	// explore it's neighbours
	for(int i=0;i<n;i++)
	{
		if(i==start)
		{
			continue;
		}
		if(visited[i]==true)
		{
			continue;
		}
		if(visited[i]==false)
		{
			int temp = dfs(adj,i,n,visited);
			if(temp!=INT_MAX)
			{
				temp+=adj[start][i];

			}
			cost = min(cost,temp);
			check = 1;
		}
	}
	if(check==0)// leaf node
	{
		visited[start]=false;
		return adj[start][0];
	}
	visited[start]=false;
	return cost;



}

int solve2(int** adj,int n,int m)
{
	int min_value = INT_MAX;
	vector<bool> visited;
	visited.assign(n,false);
	return dfs(adj,0,n,visited);
}


int solve(int** adj,int n,int m)
{
	vector<int> temp;
	int src = 0;
	for(int i=0;i<n;i++)
	{
		if(i==src)
		{
			continue;
		}
		temp.push_back(i);
	}
	int min_cost = INT_MAX;
	do
	{
		int cost = 0;
		for(int i=0;i<temp.size()-1;i++)
		{
			cost+=adj[temp[i]][temp[i+1]];
		}
		cost+= adj[src][temp[0]]+adj[temp[temp.size()-1]][src];
		min_cost =min(min_cost,cost);

	}while(next_permutation(temp.begin(),temp.end()));
	return min_cost;
}

// using dp and bit masking
int solve3(int** adj,int n,int m,int** dp,int visited,int start)
{
	if(dp[visited][start]!=-1)
	{
		return dp[visited][start];
	}
	// mark start as visited
	visited = visited | (1 << start);
	// if it is a  leaf node
	if(visited == ((1<<n)-1))
	{
		return adj[start][0];
	}
	int cost = INT_MAX;
	// explore it's neigbours
	for(int i=0;i<n;i++)
	{
		if(i==start)
		{
			continue;
		}
		if((visited & (1<< i))==0 && adj[start][i]!=0)
		{
			int temp =solve3(adj,n,m,dp,visited,i);
			if(temp!=INT_MAX)
			{
				temp+=adj[start][i];
			}
			cost = min(cost,temp);
		}
	}
	return cost;


}

int main()
{
	int n,m;
	cin >> n >> m;
	int** adj = new int*[m];
	for(int i=0;i<m;i++)
	{
		adj[i]=new int[n]();
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		adj[a-1][b-1]=c;
		adj[b-1][a-1]=c;
	}
	cout << solve2(adj,n,m) << endl;
	cout << solve(adj,n,m) << endl;
	int** dp = new int*[(1<<n)];
	for(int i=0;i<(1<<n);i++)
	{
		dp[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout << solve3(adj,n,m,dp,0,0) << endl;
	delete[] dp;

	return 0;
}