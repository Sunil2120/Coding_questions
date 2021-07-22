#include<bits/stdc++.h>
using namespace std;


bool solve(int* arr,int n)
{
	int total=0;
	for(int i=0;i<n;i++)
	{
		total+=arr[i];
	}
	if(total&1)
	{
		return false;// odd
	}
	int value = total/2;
	bool** dp = new bool*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new bool[value+1]();
	}
	// if(sum==0)
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=true;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=value;j++)
		{
			// exclude
			dp[i][j]=dp[i-1][j];
			//include
			if(j-arr[i-1] >=0)
			{
				dp[i][j]=dp[i][j]||dp[i-1][j-arr[i-1]];
			}
		}
	}
	bool ans = dp[n][value];
	delete[] dp;
	return ans;

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