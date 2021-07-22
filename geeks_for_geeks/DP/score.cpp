#include<bits/stdc++.h>
using namespace std;

int solve(int n,int numD,int* deno,int** dp)
{
	if(n==0)
	{
		return 1;
	}
	if(n!=0 && numD==0)
	{
		return 0;
	}
	if(n < 0)
	{
		return 0;
	}
	if(dp[n][numD]!=-1)
	{
		return dp[n][numD];
	}
	int first = solve(n-deno[0],numD,deno,dp);
	int second = solve(n,numD-1,deno+1,dp);
	dp[n][numD]=first+second;
	return dp[n][numD];
}


int main()
{
	int n;
	cin >> n;
	int* deno = new int[3];
	deno[0]=3;
	deno[1]=5;
	deno[2]=10;
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[4];
		for(int j=0;j<=3;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout << solve(n,3,deno,dp) << endl;
	delete[] dp;
	delete[] deno;
	return 0;
}