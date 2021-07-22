#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int V,int M)
{
	if(V==0)
	{
		return 0;
	}
	if(M==0)
	{
		return INT_MAX;
	}
	//include cur coin
	int temp1 = INT_MAX;
	if(arr[0] <= V)
	{
		temp1 = 1+solve(arr,V-arr[0],M);
	}
	//exclude
	int temp2 = solve(arr+1,V,M-1);
	return min(temp1,temp2);
}

int solve2(int* arr,int V,int M)
{
	int** dp = new int*[V+1];
	for(int i=0;i<=V;i++ )
	{
		dp[i]=new int[M+1];
		for(int j=0;j<=M;j++)
		{
			dp[i][j]=100000;
		}
	}
	for(int i=0;i<=M;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=M;j++)
		{
			dp[i][j]=dp[i][j-1];
			int temp = dp[i-arr[j-1]][j];
    		if(temp!=100000)
    		{
    			temp+=1;
    		}
			if(arr[j-1]<=i)
			{
				dp[i][j]=min(dp[i][j],temp);
			}
		}
	}
	int min_value =100000;
	for(int i=0;i<=M;i++)
	{
		min_value = min(min_value,dp[V][i]);
	}
	if(min_value==100000)
	{
		return -1;
	}
	return min_value;
}

int main()
{
	int V,M;
	cin >> V >> M;
	int* arr = new int[M];
	for(int i=0;i<M;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,V,M) << endl;
	cout << solve2(arr,V,M) << endl;
	return 0;
}