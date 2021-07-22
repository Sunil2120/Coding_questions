//Maximum path sum in matrix
#include<bits/stdc++.h>
using namespace std;

int solve(int** arr,int m,int n)
{
	int** dp = new int*[m];
	for(int i=0;i<m;i++)
	{
		dp[i]=new int[n]();
	}
	//base case
	for(int i=0;i<n;i++)
	{
		dp[m-1][i]=arr[m-1][i];
	}
	for(int i=m-2;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			int option1 = dp[i+1][j];//down
			int option2 = 0;
			int option3 = 0;
			
			// down-left
			if(j-1 >=0 )
			{
				option2 = dp[i+1][j-1];
			}
			// down-right
			if(j+1 < n)
			{
				option3 = dp[i+1][j+1];
			}
			dp[i][j]=max(option1,max(option2,option3))+arr[i][j];
		}
	}
	int max_ = INT_MIN;
	for(int i=0;i<n;i++)
	{
		max_ = max(max_,dp[0][i]);
	}
	for(int i=0;i<m;i++)
	{
		delete[] dp[i];
	}
	return max_;
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
	cout  << solve(arr,m,n) << endl;
	for(int i=0;i<m;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}