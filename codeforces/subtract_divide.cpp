#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
	if(n==1)
	{
		return 0;
	}
	int option1=INT_MAX;
	for(int i=2;i<n;i++)
	{
		if(n%i == 0)
		{
			option1=min(option1,solve(n/i));
		}
	}
	int option2=solve(n-1);
	return min(option2,option1)+1;
}

int solve2(int n)
{
	if(n==1)
	{
		return 0;
	}
	int* dp=new int[n+1]();
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		int option1=dp[i-1];
		int option2=INT_MAX;
		for(int j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				option2=dp[i/j];
			}
		}
		dp[i]=min(option1,option2)+1;
	}
	return dp[n];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << solve2(n) << endl;
	}
	return 0;
}