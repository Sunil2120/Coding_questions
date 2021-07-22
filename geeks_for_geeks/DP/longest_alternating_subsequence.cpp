#include<bits/stdc++.h>
using namespace std;



int solve(int* arr,int n)
{
	vector<pair<int,int>> dp;
	dp.assign(n,make_pair(0,0));
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			dp[i]=make_pair(1,-1);
			continue;
		}
		int max_value = INT_MIN;
		int pos = -1;
		for(int j=i-1;j>=0;j--)
		{
			if(dp[j].second==-1)
			{
				if(arr[i] > arr[j])
				{
					int temp = dp[j].first+1;
					if(temp > max_value)
					{
						max_value = temp;
						pos = 1;

					}
				}
				else
				{
					int temp = dp[j].first+1;
					if(temp > max_value)
					{
						max_value = temp;
						pos = 0;
					}
				}
			}
			else
			{
				if(arr[i] > arr[j] && dp[j].second==0)
				{
					int temp = dp[j].first+1;
					if(temp > max_value)
					{
						max_value = temp;
						pos = 1;
					}
				}
				else if(arr[i] < arr[j] && dp[j].second==1)
				{
					int temp = dp[j].first+1;
					if(temp > max_value)
					{
						max_value = temp;
						pos = 0;
					}
				}
			}
			dp[i].first = max_value;
			dp[i].second = pos;
		}
	}
	int max_value = INT_MIN;
	for(int i=0;i<n;i++)
	{
		max_value = max(max_value,dp[i].first);
	}
	return max_value;
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
	cout << solve(arr,n) << endl;
	return 0;
}