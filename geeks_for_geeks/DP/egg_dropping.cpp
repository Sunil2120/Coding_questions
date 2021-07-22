#include<bits/stdc++.h>
using namespace std;

// recursion
int solve(int n,int k)
{
	//base cases
	if(n==0)
	{
		return 0;// number of eggs is equal to zero
	}
	if(k==0 || k==1)
	{
		return k;// if floors = 0,1 return 0 or 1 attempt
	}
	if(n==1)
	{
		return k;// if number of egg is one in worst case we will check all floors
	}
	int min_value = INT_MAX;
	for(int i=1;i<=k;i++)
	{
		// at each floor we have two possibilities
		// 1. egg breaks
		// 2. egg does not break
		int temp1 = solve(n,k-i);//egg doesnot breaks
		int temp2 = solve(n-1,i-1);//egg breaks
		min_value =min(min_value,max(temp1,temp2)) ;
	}
	return min_value+1;
}

// dp time O(n*k*k),auxillary space O(n*k)
int solve2(int n,int k)
{
	int** dp = new int*[n+1];// eggs
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[k+1];
	}
	for(int i=0;i<=n;i++)// if k==0,1 thn ans is k
	{
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(int i=0;i<=k;i++)
	{
		dp[1][i]=i;
	}
	for(int i=0;i<=k;i++)// if number of eggs is zero thn zero
	{
		dp[0][i]=0;
	}
	
	for(int i=2;i<=n;i++)//eggs
	{
		for(int j=2;j<=k;j++)//floors
		{
			dp[i][j]=INT_MAX;
			for(int f=1;f<=j;f++)
			{
				int res = max(dp[i-1][f-1],dp[i][j-f]);
				dp[i][j]=min(dp[i][j],res);
			}
			dp[i][j]+=1; 
		}
	}
	int ans = dp[n][k];
	delete[] dp;
	return ans;

}

int main()
{
	int n,k;
	cin >> n >> k; //(n=> eggs,k=> floors)
	cout << solve(n,k) << endl;
	cout << solve2(n,k) << endl;
	return 0;
}