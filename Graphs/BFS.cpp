#include<bits/stdc++.h>
using namespace std;


void printbfs(int** edges,int n,int start,bool* visited)
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		cout << q.front() << endl;
		for(int i=0;i<n;i++)
		{
			if(i==q.front())
			{
				continue;
			}

			if(edges[q.front()][i]==1)
			{
				if(visited[i]==false)
				{
					q.push(i);
					visited[i]=true;
				}

			}
		}
		q.pop();
	}
	return ;
}


void BFS(int** edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		printbfs(edges,n,i,visited);
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
	
	BFS(edges,n);
	for(int i=0;i<n;i++)
	{
		delete[] edges[i];
	}
	delete[] edges;

	return 0;
}