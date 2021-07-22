#include<bits/stdc++.h>
using namespace std;

bool isPossible(int x,int y,int m,int n)
{
	if(x < 0 || x >= m || y<0 || y>=n)
		return false;
	return true;
}

void dfs(int** arr,int x,int y,int m,int n,bool** visited,int& min_steps,int cur)
{
	cout << "hello" << endl;
	if(y==n-1)
	{
		cout << "stop" << endl;
		min_steps = min(min_steps,cur);
		return ;
	}
	visited[x][y]=true;
	//explore it's neighbours
	int row[4]={-1,1,0,0};
	int col[4]={0,0,-1,1};
	for(int i=0;i<4;i++)
	{
		int rx = x + row[i];
		int ry = y + col[i];
		if(isPossible(rx,ry,m,n) && visited[rx][ry]==false)
		{
			dfs(arr,rx,ry,m,n,visited,min_steps,cur+1);
		}
	}
	visited[x][y]=false;
	return ;

}

int solve(int** arr,int m,int n)
{
	bool** visited = new bool*[m];
	for(int i=0;i<m;i++)
	{
		visited[i]=new bool[n]();
	}
	for(int i=0;i<m;i++)
	{
		if(arr[i][0]==1)
		{}
	}
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
	cout << solve(arr,m,n) << endl;
	return 0;
}