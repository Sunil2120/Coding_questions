#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int n)
{
	int* dp = new int[n];
	dp[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+arr[i];
	}
	int total = 0;
	for(int i=0;i<n;i++)
	{
		int prev = i-1;
		int sum = 0;
		if(prev >=0)
		{
			sum=dp[prev];
		}
		for(int j=i;j<n;j+=2)
		{
			total+=dp[j]-sum;
		}
	}
	return total;
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