#include<bits/stdc++.h>
using namespace std;

bool isPossible(int x,int y,int m,int n)
{
	if (x>=m || x<0 || y>=n || y < 0)
		return false;
	return true;
}

void dfs(int x,int y,int** arr,bool** visited,int m,int n,int x1,int y1,int cur,int& max_length)
{
	if(x==x1 && y==y1)
	{
		max_length = max(max_length,cur);
		return ;
	}
	visited[x][y]=true;
	int row[4]={-1,1,0,0};
	int col[4]={0,0,-1,1};
	for(int i=0;i<4;i++)
	{
		int rx = x+row[i];
		int ry = y+col[i];
		if(isPossible(rx,ry,m,n) && visited[rx][ry]==false && arr[rx][ry]==1)
		{
			dfs(rx,ry,arr,visited,m,n,x1,y1,cur+1,max_length);
		}
	}
	visited[x][y]=false;
	return ;
}
int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	bool** visited = new bool*[m];
	for(int i=0;i<m;i++)
	{
		visited[i]=new bool[n]();
	}
	int src_x,src_y;
	int dest_x,dest_y;
	cin >> src_x >> src_y;
	cin >> dest_x >> dest_y;
	int max_length = INT_MIN;
	 dfs(src_x,src_y,arr,visited,m,n,dest_x,dest_y,0,max_length);
	 cout << max_length << endl;
	return 0;
}