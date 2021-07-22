// triangles in graph  works for both directed and undirected
// for directed graph divide by 3
// for undirected graph divide by 6
#include<bits/stdc++.h>
using namespace std;


int solve(int** adj,int n,int m)
{
	if(n <= 2)
	{
		return 0;
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[i][j]==1)
			{
				for(int k=0;k<n;k++)
				{
					if(k==i)
					{
						continue;
					}
					if(adj[j][k]==1 && adj[k][i]==1)
					{
						count+=1;
					}
				}
			}
		}
	}
	return count/6;//  undirected
}

int main()
{
	int n,m;
	cin >> n >> m;
	int** adj = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]= new int[n]();
	}
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;// undirected graph
		adj[f][s]=1;
		adj[s][f]=1;
	}
	cout << solve(adj,n,m) << endl;
	return 0;
}