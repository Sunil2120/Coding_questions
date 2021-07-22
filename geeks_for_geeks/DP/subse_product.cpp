// Count all subsequences having product less than K
// Last Updated: 21-12-2018
// Given a non negative array, find the number of subsequences having product smaller than K.

#include<bits/stdc++.h>
using namespace std;

// This problem can be solved using dynamic programming where dp[i][j] = number of subsequences having 
// product less than i using first j terms of the array. Which can be obtained by : number of subsequences 
// using first j-1 terms + number of subsequences that can be formed using j-th term.

int solve(int* arr,int n,int k)
{

	//dp[i][j] => number of sequences having product less than i considering first j terms
	int** dp = new int*[k+1];
	for(int i=0;i<=k;i++)
	{
		dp[i]=new int[n+1]();
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(arr[j-1] < i && arr[j-1]!=0)
			{
				dp[i][j]+=dp[i/arr[j-1]][j-1]+1;
			}
		}
	}
	int ans = dp[k][n];
	delete[] dp;
	return ans;
	

}

int main()
{
	int n,k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k)<< endl;
	return 0;
}