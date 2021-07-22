#include<bits/stdc++.h>
using namespace std;


int solve(int n,int nd,int* d)
{
	if(n==0)
	{
		return 1;
	}
	if(nd==0)
	{
		return 0;
	}
	//ignore
	int temp = solve(n,nd-1,d+1);
	int temp1 = 0;
	if(d[0] <= n)
	{
		temp1 = solve(n-d[0],nd,d);
	}
	return temp1+temp;
}

int solve2(int n,int nd,int* d)
{
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[nd+1];
	}
	for(int i=0;i<=nd;i++)
	{
		dp[0][i]=1;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=nd;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(d[j-1]<=i)
			{
				dp[i][j]+=dp[i-d[j-1]][j];
			}
		}
	}
	return dp[n][nd];

}

int main()
{
	int n;
	cin >> n;
	int* d = new int[3];
	d[0]=3;
	d[1]=5;
	d[2]=10;
	cout << solve(n,3,d) << endl;
	cout << solve2(n,3,d) << endl;

	return 0;
}