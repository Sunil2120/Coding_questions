#include<bits/stdc++.h>
using namespace std;

// time-complexity o(m*n) auxillary space o(n)
int solve(string a,string b)
{
	int m = a.size();
	int n = b.size();

	int** dp = new int*[2];
	for(int i=0;i<2;i++)
	{
		dp[i]=new int[n+1]();
	}
	int cur = 1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[cur][j]=1+dp[cur^1][j-1];
			}
			else
			{
				dp[cur][j]=max(dp[cur^1][j],dp[cur][j-1]);
			}
		}
		cur = cur^1;
	}
	int ans = dp[cur^1][n];
	for(int i=0;i<2;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		
		string a,b;
		cin >> a >> b;
		cout << solve(a,b) << endl;
	}
	return 0;
}