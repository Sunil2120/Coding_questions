#include<bits/stdc++.h>
using namespace std;

bool ispossible(int x,int y,int m,int n,bool** visited)
{

	if(x < 0 || x >= m || y < 0 || y >= n)
	{
		return false;
	}
	if(visited[x][y]==true)
	{
		return false;
	}
	return true;
}

bool check(char** grid,int m,int n,int x,int y,int si,int sj,bool** visited,int count)
{
	count+=1;
	// cout << "hello" << endl;
	// cout << x << " " << y << endl;
	// if(x == si && y == sj)
	// {
	// 	return true;
	// }
	// if(visited[x][y]==true)
	// {
	// 	return false;
	// }
	visited[x][y]=true;
	int row[4] ={-1,1,0,0};
	int col[4]={0,0,-1,1};
	for(int i=0;i<4;i++)
	{
		int rx = x + row[i];
		int ry = y + col[i];
		if(rx==si && ry==sj && grid[rx][ry]==grid[x][y] && count >= 4)
		{
			return true;
		}
		if(ispossible(rx,ry,m,n,visited) && grid[rx][ry]==grid[x][y])
		{
			cout << "two" << " " << x << " " << y << " " << rx << " " << ry << endl;
			bool temp = check(grid,m,n,rx,ry,si,sj,visited,count);
			if(temp==true)
			{
				return true;
			}
		}
	}
	visited[x][y]=false;
	return false;
}

bool solve(char** grid,int m,int n)
{
	if(n==0 || m==0)
	{
		return false;
	}
	bool** visited = new bool*[m];
	for(int i=0;i<m;i++)
	{
		visited[i]=new bool[n]();
	}
	int row[4] ={-1,1,0,0};
	int col[4]={0,0,-1,1};
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<4;k++)
			{
				int rx = i + row[k];
				int ry = j + col[k];
				if(ispossible(rx,ry,m,n,visited) && grid[rx][ry]==grid[i][j])
				{
					visited[i][j]=true;
					//cout << i << " " << j << " " << rx << " " << ry << endl;
					bool temp = check(grid,m,n,rx,ry,i,j,visited,1);
					if(temp)
					{
						return true;
					}
					visited[i][j]=false;
				}
			}
			
		}
	}
	return false;
}


int main()
{
	int m,n;
	cin >> m >> n;
	char** grid = new char*[m];
	for(int i=0;i<m;i++)
	{
		grid[i]=new char[n];
		for(int j=0;j<n;j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << solve(grid,m,n) << endl;
}