//Permutation of numbers such that sum of two consecutive numbers is a perfect square
// we will use hamiltonion path
#include<bits/stdc++.h>
using namespace std;

bool isperfect(int n)
{
	int temp = sqrt(n);
	temp = temp * temp;
	if(temp==n)
	{
		return true;
	}
	return false;
}

void getparent(vector<int>& parent,int index)
{
	if(parent[index]==-1)
	{
		cout << index << endl;
		return ;
	}
	cout << index << " ";
	return getparent(parent,parent[index]);
}

bool dfs(map<int,vector<int>>& adj,int start,vector<bool>& visited,int n,vector<int>& parent)
{
	visited[start]=true;
	// check everything is visited
	int check = 0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==false)
		{
			check = 1;
			break;
		}
	}
	if(check==0)
	{
		getparent(parent,start);
		return true;
	}
	// explore it's neighbours
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(visited[next]==false)
		{
			parent[next]=start;
			bool temp = dfs(adj,next,visited,n,parent);
			if(temp)
			{
				return true;
			}
		}
	}
	visited[start]=false;
	return false;
}

bool solve(map<int,vector<int>>& adj,int n)
{
	vector<bool> visited;
	visited.assign(n+1,false);
	vector<int> parent;
	parent.assign(n+1,0);
	for(int i=1;i<=n;i++)
	{
		parent[i]=-1;
		bool temp = dfs(adj,i,visited,n,parent);
		if(temp==true)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int n;
	cin >> n;
	map<int,vector<int>> adj;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(isperfect(i+j)==true)
			{
				//cout << i << " " << j << endl;
				adj[i].push_back(j);
			}
		}
	}
	cout << solve(adj,n) << endl;
}