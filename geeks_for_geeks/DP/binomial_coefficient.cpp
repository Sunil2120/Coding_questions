#include<bits/stdc++.h>
using namespace std;

// recurssion
int solve(int n,int r)
{
	if(r > n)
	{
		return 0;
	}
	if(r==0 || r==n)
	{
		return 1;
	}
	if(r==1)
	{
		return n;
	}
	return solve(n-1,r-1)+solve(n-1,r);
}
// iterative
int solve2(int n,int r)
{	
	int ans = 0;
	int* dp = new int[r+1]();
	for(int i=0;i<=n;i++)
	{
		for(int j=r;j>=0;j--)
		{
			if(j > i)
			{
				continue;
			}
			else if(j==i)
			{
				dp[j]=1;
			}
			else if(j==0)
			{
				dp[j]=1;
			}
			else if(j==1)
			{
				dp[j]=i;
			}
			else
			{
				dp[j]=dp[j]+dp[j-1];
			}
		}
		ans = dp[r];
	}
	delete[] dp;
	return ans;
}


int main()
{
	int n,r;
	cin >> n >> r;
	cout << solve(n,r) << endl;
	cout << solve2(n,r) << endl;
}