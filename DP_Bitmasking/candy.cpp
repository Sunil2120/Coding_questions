#include<bits/stdc++.h>
using namespace std;



long long solve(int** arr,int n,int cur_p,int mask)
{
	if(mask==((1<<n)-1))
	{
		return 1;
	}
	if(cur_p >=n)
	{
		return 0;
	}
	int temp = mask;
	int k=0;
	while(temp>0)
	{
		if(temp%2==1)
		{
			k++;
		}
		temp=temp/2;
	}
	long long result = 0;
	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			if(arr[k][i]==1)
			{
				result+=solve(arr,n,cur_p+1,mask|(1<<i));
			}
		}
	}
	return result;

}

long long solve2(int** arr,int n,int cur_p,int mask,long long* dp)
{
	if(mask==((1<<n)-1))
	{
		return 1;
	}
	if(cur_p==n)
	{
		return 0;
	}
	if(dp[mask]!=0)
	{
		return dp[mask];
	}
	int temp = mask;
	int k=0;
	while(temp>0)
	{
		if(temp%2==1)
		{
			k++;
		}
		temp=temp/2;
	}
	long long result = 0;
	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			if(arr[k][i]==1)
			{
				result+=solve(arr,n,cur_p+1,mask|(1<<i),dp);
			}
		}
	}
	dp[mask]=result;
	return result;
}

int main()
{
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>> arr[i][j];
		}
	}
	long long* dp = new long long[1<<n]();
	cout << solve2(arr,n,0,0,dp) << endl;
	delete[] dp;
	return 0;
}