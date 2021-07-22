#include<bits/stdc++.h>
using namespace std;

bool compare(long a,long b)
{
	return a > b;
}


long solve(int n,int k,long* input)
{
	if(n==0)
	{
		return 0;
	}
	sort(input,input+n,compare);
	long min_x = INT_MAX;
	long max_x = INT_MIN;
	long* dp = new long[n]();
	if(input[0] >= k)
	{
		dp[0]=input[0]-k;
		cout << dp[0] << endl;
	}
	else
	{
		dp[0]=input[0]+k;
		cout << dp[0] << endl;
	}
	if(dp[0] > max_x)
	{
		max_x = dp[0];
	}
	if(dp[0] < min_x)
	{
		min_x = dp[0];
	}
	for(int i=1;i<n;i++)
	{
		long sub = input[i] - k;
		if(sub < 0)
		{
			dp[i]=input[i]+k;
			cout << dp[i] << endl;
			continue;
		}
		long add = input[i] + k;
		long  max_a = max_x;
		long min_a = min_x;
		if(add > max_a)
		{
			max_a = add;
		}
		if(add < min_a)
		{
			min_a = add;
		}
		long temp = max_a - min_a;
		long max_s = max_x;
		long min_s = min_x;
		if(sub < min_s)
		{
			min_s = sub;
		}
		if(sub > max_s)
		{
			max_s = sub;
		}
		int temp1 = max_s - min_s;
		if(temp < temp1)// we need minimum
		{
			dp[i]= add;
			cout << dp[i] << endl;
			max_x = max_a;
			min_x = min_a;
		}
		else
		{
			dp[i]= sub;
			cout << dp[i] << endl;
			max_x = max_s;
			min_x = min_s;
		}
	}

	sort(dp,dp+n);

	return (dp[n-1] - dp[0]);
	

}



int main()
{
	long n,k;
	cin >> n >> k;
	long* input = new long[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << solve(n,k,input) << endl;
	return 0;
}