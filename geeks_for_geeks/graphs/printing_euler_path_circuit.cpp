#include<bits/stdc++.h>
using namespace std;

// step1: graph should be Euler Graph
// step2 : if euler path => starting vertex is one with odd degree
//			if euler circuit=> any vertex
// step3 : remove edges one by one
// step4 : non-bridge edges has higher priority than bridge edge for removing

int get_start(int** adj,int n)
{
	vector<int> degree(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[i][j]==1)
			{
				degree[j]+=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << degree[i] << " ";
	}
	cout << endl;
	for(int i=0;i<n;i++)
	{
		if((degree[i]%2)!=0)//odd
		{
			return i;
		}
	}
	return 0;
}

bool isBridge(int** adj,int u,int v,int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(adj[v][i]==1)
		{
			count+=1;
		}
	}
	if(count > 1)// single edge
	{
		return false;
	}
	
	return true;
}



void solve(int** adj,int start,int n,int& edges)
{

	//remove edges one by one
	for(int i=0;i<n;i++)
	{
		if(adj[start][i]==1)// u and v edge
		{
			//u-> v edge is not a bridge
			if(isBridge(adj,start,i,n)==false || edges <=1)
			{

				cout << start << " ------> " << i << endl; 
				//remove
				adj[start][i]=0;
				adj[i][start]=0;
				edges-=1;
				
				solve(adj,i,n,edges);
			}
		}
	}
	return ;

}
int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	int** adj = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u][v]=1;
		adj[v][u]=1;//undirected graph
	}
	int edges = e;
	int start = get_start(adj,n);
	solve(adj,start,n,edges);
	return 0;
}