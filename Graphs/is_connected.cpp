#include<bits/stdc++.h>
using namespace std;

void dfs(int** edges,int n,int start,bool* visited)
{
	visited[start]=true;
	for(int i=0;i<n;i++)
	{
		if(start==i)
		{
			continue;
		}
		if(visited[i])
		{
			continue;
		}
		if(edges[start][i]==1)
		{
			dfs(edges,n,i,visited);
		}
	}
	return ;
}

bool check_connected(int** edges,int n)
{
	// dfs is used
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	dfs(edges,n,0,visited);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			return false;
		}
	}
	return true;


}

int main()
{
	int V,E;
	cin >> V >> E;
	int** edges = new int*[V];
	for(int i=0;i<V;i++)
	{
		edges[i]=new int[V]();
	}
	for(int i=0;i<E;i++)
	{
		int start ,end ;
		cin >> start >> end;
		edges[start][end]=1;
		edges[end][start]=1;
	}
	if(check_connected(edges,V))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;

}