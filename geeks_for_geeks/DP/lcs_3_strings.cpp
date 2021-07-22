#include<bits/stdc++.h>
using namespace std;

int solve(string first,string second,string third,int m,int n,int l)
{
	int*** dp = new int**[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i]=new int*[n+1];
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=new int[l+1]();
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=l;k++)
			{
				if(first[i-1]==second[j-1] && second[j-1]==third[k-1])
				{
					dp[i][j][k]=1+dp[i-1][j-1][k-1];
				}
				else 
				{
					dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	int ans = dp[m][n][l];
	delete[] dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int m,n,l;
	    cin >> m >> n >> l;
	    string first,second,third;
	    cin >> first >> second >> third;
	    cout << solve(first,second,third,m,n,l) << endl;
	}
	return 0;
}