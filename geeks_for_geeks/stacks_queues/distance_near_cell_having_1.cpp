#include<bits/stdc++.h>
using namespace std;


void solve(int** arr,int n,int m)
{
	int** dist = new int*[n];
	bool** visited = new bool*[n];
	for(int i=0;i<n;i++)
	{
		dist[i]=new int[m];
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
		{
			dist[i][j]=INT_MAX;
			visited[i][j]=false;
		}
	}
	queue<pair<int,int>> Q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==1)
			{
				dist[i][j]=0;
				visited[i][j]=true;
				Q.push(make_pair(i,j));
			}
		}
	}
	while(!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		// exploring all it's neighbours
		// top
		int x = cur.first -1;
		int y = cur.second;
		if(x >=0 && y < m && visited[x][y]==false)
		{
			dist[x][y]=min(dist[x][y],dist[cur.first][cur.second]+1);
			visited[x][y]=true;
			Q.push(make_pair(x,y));
		}
		//bottom
		x = cur.first + 1;
		y = cur.second;
		if(x < n && y < m && visited[x][y]==false)
		{
			dist[x][y]=min(dist[x][y],dist[cur.first][cur.second]+1);
			visited[x][y]=true;
			Q.push(make_pair(x,y));
		}
		//left
		x = cur.first;
		y = cur.second - 1;
		if(x < n && y >=0 && visited[x][y]==false)
		{
			dist[x][y]=min(dist[x][y],dist[cur.first][cur.second]+1);
			visited[x][y]=true;
			Q.push(make_pair(x,y));
		}

		// right
		x = cur.first;
		y = cur.second + 1;
		if(x < n && y < m && visited[x][y]==false)
		{
			dist[x][y]=min(dist[x][y],dist[cur.first][cur.second]+1);
			visited[x][y]=true;
			Q.push(make_pair(x,y));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	delete[] dist,visited;
	return ;
}

int main()
{

	int n,m;
	cin >> n >> m;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		}
	}
	solve(arr,n,m);
	return 0;
}