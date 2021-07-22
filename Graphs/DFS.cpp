#include<bits/stdc++.h>
using namespace std;
// undirected graphs


void printdfs(int** edges,int n,int start,bool* visited)
{
	cout << start << endl;
	visited[start]=true;// visited
	for(int i=0;i<n;i++)
	{
		if(i==start)// no loops
		{
			continue;
		}
		// if already visited
		if(visited[i])
		{
			continue;
		}
		if(edges[start][i]==1)
		{
			printdfs(edges,n,i,visited);
		}
	}
	return ;
}

void DFS(int** edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printdfs(edges,n,i,visited);
		}
	}
	delete[] visited;
	return ;

}


int main()
{
	int n;//vertices
	cin >> n;
	int e;//edges
	cin >> e;
	int**edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	DFS(edges,n);
	for(int i=0;i<n;i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
	

	return 0;
}