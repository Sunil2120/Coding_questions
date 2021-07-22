#include<bits/stdc++.h>
using namespace std;


void dfs(int** edges,int n,int start,bool* visited)
{
	visited[start]=true;
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
		if(edges[start][i]==1)
		{
			dfs(edges,n,i,visited);
		}
	}
	return ;
}



int no_connected(int** edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			count+=1;
			dfs(edges,n,i,visited);
		}
	}
	delete[] visited;
	return count;
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
		int first,second;
		cin >> first >> second;
		edges[first-1][second-1]=1;
		edges[second-1][first-1]=1;
	}
	cout << no_connected(edges,V) << endl;
	return 0;
}