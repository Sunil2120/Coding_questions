#include<bits/stdc++.h>
using namespace std;


int getminvertex(int* weight,bool* visited,int V)
{
	int minvertex = -1;
	int min_x = INT_MAX;
	for(int i=0;i<V;i++)
	{
		if(visited[i])
		{
			continue;
		}
		if(weight[i] < min_x)
		{
			min_x = weight[i];
			minvertex = i;
		}

	}
	return minvertex;
}


void solve(int** edges,int V,int E)
{
	bool* visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	int* parent = new int[V]();
	int* weight = new int[V]();
	for(int i=0;i<V;i++)
	{
		weight[i]=INT_MAX;
	}
	weight[0]=0;
	parent[0]=-1;
	for(int i=0;i<V-1;i++)
	{
		int minvertex = getminvertex(weight,visited,V);
		visited[minvertex]=true;
		// explore adjacent vertices of minvertex and changing there weight and parent accordingly
		for(int j=0;j<V;j++)
		{
			if(j==minvertex)
			{
				continue;
			}
			if(visited[j])// if there are visited ignore
			{
				continue;
			}
			if(edges[minvertex][j]!=0)// there is a edge b/w them
			{
				if(weight[j] > edges[minvertex][j])
				{
					weight[j]=edges[minvertex][j];
					parent[j]=minvertex;
				}

			}
		}

	}

	for(int i=1;i<V;i++)
	{
		if( parent[i] < i)
		{
			cout  << parent[i] << " " << i << " " << weight[i] << endl;
		}
		else
		{
			cout  << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}
	delete[] weight;
	delete[] parent;
	delete[] visited;
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
	solve(edges,V,E);
	for(int i=0;i<V;i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
	return 0;
}