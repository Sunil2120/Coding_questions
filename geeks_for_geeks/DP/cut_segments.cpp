#include<bits/stdc++.h>
using namespace std;

int solve1(int* arr,int n,int k)
{
	if(k==0)
	{
		return 0;
	}
	if(k < 0)
	{
		return -1;
	}
	int max_ = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int temp = solve1(arr,n,k-arr[i]);
		if(temp==-1)
		{
			continue;
		}
		max_ = max(max_,temp+1);
	}
	return max_;
}

// iterative o(n*n)
int solve(int* arr,int n,int k)
{
	vector<int> dp(k+1,-1);
	dp[0]=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp = i - arr[j];
			if(temp >=0 )
			{
				if(dp[temp]==-1)
				{
					continue;//invalid cut
				}
				dp[i]=max(dp[i],dp[temp]+1);
			}
		}
	}
	return dp[k];
}


int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	int min_value = INT_MAX;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		min_value = min(min_value,arr[i]);
	}
	cout << solve1(arr,n,k) << endl;
	cout << solve(arr,n,k) << endl;
	
	return 0;
}