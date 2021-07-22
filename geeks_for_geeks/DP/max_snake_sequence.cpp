#include<bits/stdc++.h>
using namespace std;

int solve(int** grid,int m,int n)
{
	int** dp = new int*[m];
	for(int i=0;i<m;i++)
	{
		dp[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			dp[i][j]=1;
		}
	}
	// base cases
	// last row
	for(int i=n-2;i>=0;i--)
	{
		if(grid[m-1][i]+1==grid[m-1][i+1] || grid[m-1][i]-1==grid[m-1][i+1])
		{
			dp[m-1][i]+=dp[m-1][i+1];//right
		}
	}
	// last col
	for(int i=m-2;i>=0;i--)
	{
		if(grid[i][n-1]==grid[i+1][n-1]+1 || grid[i][n-1]==grid[i+1][n-1]-1)
		{
			dp[i][n-1]+=dp[i+1][n-1];//down
		}
	}
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			// right
			int temp1 = 0;
			int temp2 = 0;
			if(j+1 < n)
			{
				if(grid[i][j+1]==grid[i][j]+1 || grid[i][j+1]==grid[i][j]-1)
				{
					temp1 = dp[i][j+1];
				}
			}
			//down
			if(i+1 < m)
			{
				if(grid[i+1][j]==grid[i][j]+1 || grid[i+1][j]==grid[i][j]-1)
				{
					temp2 = dp[i+1][j];
				}
			}
			dp[i][j]+=max(temp1,temp2);
		}
	}
	int max_value = 0;
	int max_i = -1;
	for(int i=0;i<n;i++)
	{
		if(dp[0][i] > max_value)
		{
			max_value = dp[0][i];
			max_i = i;
		}
		cout << dp[0][i] << " ";
	}
	cout << endl;
	int i= 0;
	int j = max_i;
	while(i<m && j<n &&  i>=0 && j>=0)
	{
		cout << grid[i][j] << " ";
		// right
		if(j+1 < n && (grid[i][j]==grid[i][j+1]+1 || grid[i][j]==grid[i][j+1]-1))
		{
			if(dp[i][j]==dp[i][j+1]+1)
			{
				j=j+1;
				continue;
			}
		}
		if(i+1 < m && (grid[i][j]==grid[i+1][j]+1 || grid[i][j]==grid[i+1][j]-1))
		{
			if(dp[i][j]==dp[i+1][j]+1)
			{
				i=i+1;
				continue;
			}
		}
		cout << endl;
		break;

	}
	
	return max_value;

}

int main()
{
	int m,n;
	cin >> m >> n;
	int** grid = new int*[m];
	for(int i=0;i<m;i++)
	{
		grid[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << solve(grid,m,n) << endl;
	return 0;
}