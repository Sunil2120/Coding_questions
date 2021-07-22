//Minimum cost to fill given weight in a bag 
#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int n,int w)
{
	vector<int> val,weight;
	int IMAX = 99999999;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=-1)
		{
			weight.push_back(i+1);
			val.push_back(arr[i]);
		}
	}
	n = weight.size();
	// 0 items and w weight =>INT_MAX;
	// 0 weight and N items => 0;
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[w+1]();
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=w;i++)
	{
		dp[0][i]=IMAX;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			// exclude
			if(weight[i-1] > j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j-weight[i-1]]+val[i-1]);
			}
		}
	}
	if(dp[n][w]==IMAX)
	{
		return -1;	
	}
	return dp[n][w];
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int w;
	cin >> w;
	cout << solve(arr,n,w) << endl;
	return 0;
}