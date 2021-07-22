#include<bits/stdc++.h>
using namespace std;


int solve(int** arr,int m,int n)
{
	int** dp = new int*[m];
	for(int i=0;i<m;i++)
	{
		dp[i]=new int[n]();
	}
	for(int i=0;i<m;i++)
	{
		dp[i][n-1]=arr[i][n-1];
	}
	
	for(int j=n-2;j>=0;j--)
	{
		for(int i=0;i<m;i++)
		{
			int r=0;
			int rt=0;
			int rb=0;
			if(j+1 < n)
			{
				r = dp[i][j+1];
			}
			if(i-1 >=0 && j+1 < n)
			{
				rt = dp[i-1][j+1];
			}
			if(i+1 < m && j+1 < n)
			{
				rb = dp[i+1][j+1];
			}
			dp[i][j]=max(r,max(rt,rb));
			dp[i][j]+=arr[i][j];
		}
	}
	int max_value = INT_MIN;
	for(int i=0;i<m;i++)
	{
		max_value = max(max_value,dp[i][0]);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return max_value;
}


int main()
{
	int n,m;
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