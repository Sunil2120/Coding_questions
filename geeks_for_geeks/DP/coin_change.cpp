#include<bits/stdc++.h>
using namespace std;


int solve(int n,int nd,int* d)
{
	int* dp = new int[n+1]();
	int ans = 0;
	for(int i=0;i<nd;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j==0)
			{
				dp[j]=1;
				continue;
			}
			if(j-d[i] >=0)
			{
				dp[j]+=dp[j-d[i]];
			}
		}
	}
	return dp[n];
}


int main()
{
	int n,nd;
	cin >> n >> nd;
	int* d = new int[nd];
	for(int i=0;i<nd;i++)
	{
		cin >> d[i];
	}
	cout << solve(n,nd,d) << endl;
	return 0;
}