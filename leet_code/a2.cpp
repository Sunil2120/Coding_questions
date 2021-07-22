#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n,int k)
{
	long long total = 0;
	for(int i=0;i<n;i++)
	{
		total+=arr[i];
	}
	if(total < k)
	{
		return -1;
	}
	if(total%k == 0)
	{
		return 0;
	}
	long long* dp = new long long[n]();
	long long value = total - (total%k);
	while(value >= 0)
	{
		
		cout <<  value << endl;
		unordered_map<long long,int> s;
		for(int i=0;i<n;i++)
		{
			dp[i]=arr[i];
			if(i-1>=0)
			{
				dp[i]+=dp[i-1];
			}
		}
		int min_i = INT_MAX;
		//cout << value << endl;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==value)
			{
				min_i = 1;
				break;
			}
			int required = dp[i]-value;
			//cout  << required << endl;
			if(s.find(required)!=s.end())
			{
				cout << s[required] << endl;
				min_i = min(min_i,s[required]);
			}
			s[dp[i]]=i+1;
		}
		if(min_i!=INT_MAX)
		{
			return min_i;
		}
		value-=k;
	}
	return -1;
	
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << solve(arr,n,k) << endl;
}