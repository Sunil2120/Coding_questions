// Minimum Number of Days to Disconnect Island

// Link to the Problem: Minimum Number of Days to Disconnect Island
// Problem Level: Medium

// Problem Description:
// Given a 2D grid consisting of 1’s (land) and 0’s (water).  An island is a maximal 4-directionally (horizontal or vertical) connected group of 1’s.
// The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
// In one day, we are allowed to change any single land cell (1) into a water cell (0).
// Return the minimum number of days to disconnect the grid.
//  Example 1:
// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 2
// Explanation: We need at least 2 days to get a disconnected grid.
// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.


//https://docs.google.com/document/d/1UWhOuzGhQRgBHy7_nZMcD7-URK_nJazuHw9mVPO34fk/edit
// leetcode 204 contest 3rd Q
#include<bits/stdc++.h>
using namespace std;

bool ispossible(int x,int y,int m,int n)
{
	if(x < 0 || x >=m || y < 0 || y >= n)
	{
		return false;
	}
	return true;
}

void dfs(int** arr,int sx,int sy,bool** visited,int m,int n)
{
	visited[sx][sy]=true;
	//explore it's neighbours
	// top
	if(ispossible(sx-1,sy,m,n) && arr[sx-1][sy]==1 && visited[sx-1][sy]==false)
	{
		dfs(arr,sx-1,sy,visited,m,n);
	}
	// down
	if(ispossible(sx+1,sy,m,n) && arr[sx+1][sy]==1 && visited[sx+1][sy]==false)
	{
		dfs(arr,sx+1,sy,visited,m,n);
	}
	//left
	if(ispossible(sx,sy-1,m,n) && arr[sx][sy-1]==1 && visited[sx][sy-1]==false)
	{
		dfs(arr,sx,sy-1,visited,m,n);
	}
	// right
	if(ispossible(sx,sy+1,m,n) && arr[sx][sy+1]==1 && visited[sx][sy+1]==false)
	{
		dfs(arr,sx,sy+1,visited,m,n);
	}
	return ;
}



int no_islands(int** arr,int m,int n)
{
	bool** visited = new bool*[m];
	int count = 0;
	for(int i=0;i<m;i++)
	{
		visited[i]=new bool[n]();
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(visited[i][j]==false && arr[i][j]==1)
			{
				count+=1;
				dfs(arr,i,j,visited,m,n);
			}
		}
	}
	return count;
}

int min_days(int** arr,int m,int n)
{
	if(no_islands(arr,m,n)!=1)
	{
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1)
			{
				arr[i][j]=0;
				if(no_islands(arr,m,n)!=1)
				{
					return 1;
				}
				arr[i][j]=1;
			}
		}
	}
	return 2;
}
int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];//row;
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];//col
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	
	cout << no_islands(arr,m,n) << endl;
	cout << min_days(arr,m,n) << endl;
	return 0;
}
