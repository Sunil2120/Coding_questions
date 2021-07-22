#include<bits/stdc++.h>
using namespace std;


int print_cycle(int** adj,int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		
			for(int k=0;k<n;k++)
			{
				if(adj[i][j]==1 && adj[j][k]==1 && adj[k][i]==1)
				{
						count+=1;
				}
			}
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	int** adj = new int*[n];
	int** adj2 = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n]();
		adj2[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u][v]=1;//directed
		//undirected
		adj2[u][v]=1;
		adj2[v][u]=1;
	}
	cout << print_cycle(adj,n)/3;
	cout << endl;
	cout << print_cycle(adj2,n)/6;
	return 0;
}