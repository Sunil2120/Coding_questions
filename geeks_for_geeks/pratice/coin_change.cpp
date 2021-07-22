#include<bits/stdc++.h>
using namespace std;


bool solve(int* arr,int n,int sum,int cur)
{
	if(n==0)
	{
		return false;
	}
	if(cur > sum)
	{
		return false;
	}
	if(cur==sum)
	{
		return true;
	}
	//include
	bool temp1 = solve(arr+1,n-1,sum,cur+arr[0]);
	//exclude
	bool temp2 = solve(arr+1,n-1,sum,cur);
	return temp1 || temp2;
}

bool solve2(int* arr,int n,int sum)
{
	bool** dp = new bool*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new bool[sum+1]();
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			bool option1 = false;
			bool option2 = false;
			if(arr[i-1] <= j)
			{
				option1 = dp[i-1][j-arr[i-1]];
			}
			option2 = dp[i-1][j];
			dp[i][j]=option1 || option2;
		}
	}
	return dp[n][sum];


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
	int sum = 0;
	cin >> sum;
	cout << solve2(arr,n,sum) << endl;
	return 0;
}