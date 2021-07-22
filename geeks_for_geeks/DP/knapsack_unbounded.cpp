#include<bits/stdc++.h>
using namespace std;


int solve(int n,int W,vector<int>& val,vector<int>& weights,int index)
{
	if(W==0)
	{
		return 0;
	}
	if(n==0)
	{
		return 0;
	}
	int max_value = INT_MIN;
	if(weights[index] <= W)
	{
		// include
		int temp = solve(n,W-weights[index],val,weights,index)+val[index];
		max_value = max(max_value,temp);
	}
	// exclude
	int temp2 = solve(n-1,W,val,weights,index+1);
	max_value = max(max_value,temp2);
	return max_value;
}

// dp
int solve2(int n,int W,vector<int>& val,vector<int>& weights)
{
	if(W==0)
	{
		return 0;	
	}
	if(n==0)
	{
		return 0;
	}
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[W+1]();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			// exclude
			dp[i][j]=dp[i-1][j];
			if(weights[i-1] <= j)
			{
				// include
				dp[i][j]=max(dp[i][j],dp[i][j-weights[i-1]]+val[i-1]);
			}
		}
	}
	int ans = dp[n][W];
	delete[] dp;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> val(n,0);
	vector<int> weights(n,0);
	int W;
	cin >> W;
	for(int i=0;i<n;i++)
	{
		cin >> val[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> weights[i];
	}
	cout << solve2(n,W,val,weights) << endl;
	return 0;
}