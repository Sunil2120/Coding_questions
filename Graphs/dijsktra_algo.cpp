// undirected graph
#include<bits/stdc++.h>
using namespace std;


int getminvertex(int* distance,bool* visited,int n)
{
	int min_vertex = -1;
	int min_x = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(visited[i])
		{
			continue;
		}
		if(distance[i] < min_x)
		{
			min_x = distance[i];
			min_vertex = i;
		}
	}
	return min_vertex;
}



void  solve(int** edges,int V,int start)
{
	bool* visited = new bool[V]();
	int* distance = new int[V];
	for(int i=0;i<V;i++)
	{
		distance[i]=INT_MAX;
	}
	distance[start]=0;
	for(int i=0;i<V-1;i++)
	{
		int min_vertex = getminvertex(distance,visited,V);
		visited[min_vertex]=true;
		// exploring all its neighbour nodes
		for(int j=0;j<V;j++)
		{
			if(min_vertex==j)
			{
				continue;
			}
			if(visited[j])
			{
				continue;
			}
			if(edges[min_vertex][j]!=0)
			{
				int cur = edges[min_vertex][j] + distance[min_vertex];
				if(distance[j] > cur)
				{
					distance[j]= cur;
				}
			}
		}
	}

	for(int i=0;i<V;i++)
	{
		if(i==start)
		{
			continue;
		}
		cout << start << " " << i << " " << distance[i] << endl; 
	}
	delete[] visited;
	delete[] distance;
	return ;
}


int main()
{
	int V,E;
	cin >> V >> E;
	int** edges = new int*[V];
	for(int i=0;i<V;i++)
	{
		edges[i]=new int[V];
	}
	for(int i=0;i<E;i++)
	{
		int start,end,weight;
		cin >> start >> end >> weight;
		edges[start][end]=weight;
		edges[end][start]=weight;
	}
	solve(edges,V,0);
	for(int i=0;i<V;i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
	return 0;
}