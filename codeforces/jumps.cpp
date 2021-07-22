#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr,int n)
{
	vector<int> dp(n+1,0);
	for(int i=n;i>0;i--)
	{
		dp[i]=arr[i];
		if(i+dp[i] <= n)
		{
			dp[i]+=dp[i+dp[i]];
		}
	}
	int max_value = dp[1];
	for(int i=1;i<=n;i++)
	{
		max_value = max(max_value,dp[i]);
	}
	return max_value;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n+1);
		for(int i=1;i<=n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
	}
	return 0;
}