#include<bits/stdc++.h>
using namespace std;

int solve(string a,string b)
{
	int m = a.size();
	int n = b.size();
	int** dp =new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i]=new int[n+1]();
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			{
				if(i-2 >=0 && j-2 >=0 && a[i-2]==b[j-2])
				{
					dp[i][j]=1+dp[i-1][j-1];
				}
				else
				{
					dp[i][j]=1;
				}
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int max_ = INT_MIN;
	for(int i=0;i<=m;i++)
	{
	    for(int j=0;j<=n;j++)
	    {
	        max_ = max(max_,dp[i][j]);
	    }
	}
	int ans = max_;
	delete[] dp;
	return ans;
}

int main()
{
	string a,b;
	cin >> a >> b;
	cout << solve(a,b) << endl;
}