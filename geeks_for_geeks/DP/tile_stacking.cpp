#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(int n,int m,int k,map<int,int> hash,int cur)
{
	if(n==0)
	{
		return 1;
	}
	int total = 0;
	for(int i=cur;i>=1;i--)
	{
		if(hash[i]!=0)
		{
			hash[i]--;
			total+=solve(n-1,m,k,hash,i);
			hash[i]+=1;
		}
	}
	return total;
}

// dp1 O(n*m*k)

// In Dynamic Programming we declare a 2D array dp[][], where each state dp[i][j] denotes the number of decreasing sequences of length i using numbers from 1 to j.
//  We need to take care of the fact that a number can be used a most k times. 
//  This can be done by considering 1 to k occurrences of a number. 
// Hence our recurrence relation becomes:
// dp[i][j] = sumof(dp[i-x][j-1]) where x lies between 0 to k
int solve1(int n,int m,int k,int** dp)
{
	if(n<0 || m < 0)
	{
		return 0;
	}
	if(dp[n][m]!=-1)
	{
		return dp[n][m];
	}
	
	if(n==0)// we have reached one way
	{
		dp[n][m]=1;
		return dp[n][m];
	}
	if(m==0)// no tiles
	{
		dp[n][m]=0;
		return dp[n][m];
	}

	int res = 0;
	for(int i=0;i<=k;i++)
	{
		res+=solve1(n-i,m-1,k,dp);
	}
	dp[n][m]=res;
	return dp[n][m];
}

int main()
{	
	int n,m,k;
	cin >> n >> m >> k;
	map<int,int> hash;
	for(int i=1;i<=m;i++)
	{
		hash[i]=k;
	}
	cout << solve(n,m,k,hash,n) << endl;
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[m+1];
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout << solve1(n,m,k,dp) << endl;
	delete[] dp;
	return 0;
}