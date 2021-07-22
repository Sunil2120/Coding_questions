#include<bits/stdc++.h>
using namespace std;


int findminvertex(int* distance,bool* visited,int v)
{
	int min_x = INT_MAX;
	int min_i = -1;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			if(distance[i]< min_x)
			{
				min_x = distance[i];
				min_i = i;
			}
		}
	}
	return min_i;
}



int solve(vector<int>* edges,int v)
{
	bool* visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	int* distance = new int[v];
	for(int i=0;i<v;i++)
	{
		distance[i]=INT_MAX;
	}
	distance[0]=0;
	for(int i=0;i<v;i++)
	{
		int min_vertex = findminvertex(distance,visited,v);
		visited[min_vertex]=true;
		// we will explore it's neighbour vertices
		for(int j=0;j<edges[min_vertex].size();j++)
		{
			int cur = distance[min_vertex]+1;
			int adj = edges[min_vertex][j];
			if(visited[adj]==false)
			{
				if(distance[adj]>cur)
				{
					distance[adj]=cur;
				}
			}
		}
	}
	int ans = distance[v-1];
	delete[] distance;
	delete[] visited;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int v,e;
		cin >> v >> e;
		vector<int>* edges = new vector<int>[v];
		// for(int i=0;i<v;i++)
		// {
		// 	edges[i]=new int[v]();
		// }
		for(int i=0;i<e;i++)
		{
			int x,y;
			cin >> x >> y;
			// edges[x-1][y-1]=1;
			// edges[y-1][x-1]=1;
			edges[x-1].push_back(y-1);
			edges[y-1].push_back(x-1);
		}
		cout << solve(edges,v) << endl;
		delete[] edges;
	}
}