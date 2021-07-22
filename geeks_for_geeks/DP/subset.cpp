#include<bits/stdc++.h>
using namespace std;


bool issubset(int* arr,int n,int value)
{
	bool** dp = new bool*[n+1];// items
	for(int i=0;i<=n;i++)
	{
		dp[i]=new bool[value+1]();
	}
	dp[0][0]=true;
	// every set has a subset
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=true;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=value;j++)
		{
			if(j-arr[i-1] >= 0)
			{
				// include
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];

			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	bool ans = dp[n][value];
	for(int i=0;i<=n;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;

	
}

bool solve(int* arr,int n)
{
	int sum = 0;
	// if sum is even it can be divided into two subsets
	// if sum is odd it can't be divided into two subsets
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if(sum&1)
	{
		return false;//odd
	}
	sum = sum /2;
	return issubset(arr,n,sum);
}



int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout  << solve(arr,n) << endl;
	return 0;
}