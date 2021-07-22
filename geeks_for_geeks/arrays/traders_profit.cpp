// maximum profit in trading doing atmost k transactions

#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int n,int k,int ongoing)
{
	if(k==0 || n==0)
	{
		return 0;
	}
	// ignore
	int first = solve(arr+1,n-1,k,ongoing);
	if(ongoing==0)// we should buy
	{
		int second = solve(arr+1,n-1,k,1)-arr[0];
		return max(first,second);
	}
	if(ongoing==1)//we should  sell
	{
		int third = solve(arr+1,n-1,k-1,0)+arr[0];
		return max(first,third);
	}
	return 0;

}

int solve2(int* arr,int n,int k,int*** output,int ongoing)
{
	if(k==0 || n==0)
	{
		return 0;
	}
	if(output[n][k][ongoing]!=-1)
	{
		return output[n][k][ongoing];
	}
	int first = solve2(arr+1,n-1,k,output,ongoing);// ignore
	if(ongoing==0)// buy
	{
		int second = solve2(arr+1,n-1,k,output,1)-arr[0];
		output[n][k][ongoing]=max(first,second);
	}
	else
	{
		// sell
		int third = solve2(arr+1,n-1,k-1,output,0)+arr[0];
		output[n][k][ongoing]=max(first,third);
	}
	return output[n][k][ongoing];


}

// o(n2*k)
int solve3(int* arr,int n,int k)
{
	int** dp = new int*[k+1];// transactions
	for(int i=0;i<=k;i++)
	{
		dp[i]=new int[n+1];// elements in array
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(int i=0;i<=k;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<n;j++)
		{
			int first = dp[i][j-1];// ignore
			// selling on j day
			// so we should have buyed the shares previously j
			int max_so_far = INT_MIN;
			for(int m=0;m<j;m++)
			{
				int value = arr[j]-arr[m]+dp[i-1][m];// previous profit
				max_so_far = max(max_so_far,value);
			}
			dp[i][j]=max(first,max_so_far);
		}
	}
	int ans = dp[k][n-1];// profit after k transaction on n-1th day
	for(int i=0;i<=k;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

// o(nk)
int solve4(int* arr,int n,int k)
{
	int** dp = new int*[k+1];// transactions
	for(int i=0;i<=k;i++)
	{
		dp[i]=new int[n+1];// elements in array
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(int i=0;i<=k;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=0;
	}
	for(int t=1;t<=k;t++)
	{
		int prevdiff = INT_MIN;
		for(int i=1;i<n;i++)
		{
			int first = dp[t][i-1];//ignore

			//value = arr[i] - arr[m] + dp[t-1][m]; m from 0 to i-1 stores in prevdiff
			// value = arr[i]+max(dp[t-1][m]-arr[m]);
			prevdiff = max(prevdiff,dp[t-1][i-1]-arr[i-1]);
			int value = arr[i]+prevdiff;
			dp[t][i]=max(first,value);
		}
	}
	int ans = dp[k][n-1];
	for(int i=0;i<=k;i++)
	{
		delete[] dp[i];
	}
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
	cout << solve(arr,n,k,0) << endl;
	int*** output = new int**[n+1];// n
	for(int i=0;i<=n;i++)
	{
		output[i]=new int*[k+1];//k
		for(int j=0;j<=k;j++)
		{
			output[i][j]=new int[2]();
			for(int k=0;k<2;k++)
			{
				output[i][j][k]=-1;
			}
		}
	}
	cout << solve2(arr,n,k,output,0) << endl;
	cout << solve3(arr,n,k) << endl;
	cout << solve3(arr,n,k) << endl;
}