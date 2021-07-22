// Mehta and Bank robbery problem
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	int n,w;
	cin >> n >> w;
	pair<int,int>* arr = new pair<int,int>[n];
	for(int i=0;i<n;i++)
	{
		int value,weight;
		cin >> value >> weight;
		arr[i]=make_pair(value,weight);
	}
	// we need max when multiplied with prime number so sorting on the basis of profit
	// by default sorting in pair is based on first element
	sort(arr,arr+n);
	// 3D array prime,number of elements,weight
	ll*** dp = new ll**[2];
	for(int i=0;i<2;i++)
	{
		dp[i]=new ll*[n+1];
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=new ll[w+1];
			for(int k=0;k<=w;k++)
			{
				dp[i][j][k]=0;
			}
		}
	}

	// base case
	// if number of elements is zero the ans is zero same thing goes with weight
	// by default it will be zero
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			dp[0][i][j]=dp[0][i-1][j];// not including
			if(arr[i-1].second <= j)
			{
				dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-arr[i-1].second]+arr[i-1].first);
			}
		}
	}

	int prime[11]={1,2,3,5,7,11,13,17,19,23,29};
	// p can p or p-1 so we will use only two p or p-1
	for(int k=1;k<=10;k++)
	{
		int p = k%2;// even-0 and odd-1
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=w;j++)
			{
				dp[p][i][j]=dp[p][i-1][j];//not including
				if(arr[i-1].second <= j)
				{
					dp[p][i][j]=max(dp[p][i][j],max(dp[p][i-1][j-arr[i-1].second]+arr[i-1].first,
						dp[p^1][i-1][j-arr[i-1].second]+arr[i-1].first * prime[k]));
				}

			}
		}
	}
	cout <<  dp[0][n][w] << endl;// p=0 because for 10 - 0
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<=n;j++)
		{
			delete[] dp[i][j];
		}
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}