#include<bits/stdc++.h>
using namespace std;

int solve(int n,int* dp)
{
	if(n < 10)
	{
		switch(n)
		{
			case 1:return 1;
			case 2:return 2;
			case 3:return 6;
			case 4:return 4;
			case 5:return 2;
			case 6:return 2;
			case 7:return 4;
			case 8:return 2;
			case 9:return 8;
		}

	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	int cur = (n/10)%10;
	int value = 0;
	if(cur%2 == 0)
	{
		value = 6*solve(n/5,dp)*solve(n%10,dp);
	}
	else
	{
		value = 4*solve(n/5,dp)*solve(n%10,dp);
	}
	dp[n]=value;
	return value;
}

int main()
{
	int n;
	cin >> n;
	int* dp = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	// dp[1]=1;
	// dp[2]=2;
	// dp[3]=9;
	// dp[4]=6;
	// dp[5]=2;
	// dp[6]=2;
	// dp[7]=4;
	// dp[8]=2;
	// dp[9]=8;
	cout << solve(n,dp)%10 << endl;
	return 0;
}