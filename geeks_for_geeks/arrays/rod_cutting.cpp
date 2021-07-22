// rod cutting problem
#include<bits/stdc++.h>
using namespace std;

// recursion
int solve(int l,int* len,int* profit,int n)
{
	if(l==0)
	{
		return 0;
	}
	if(l<0)
	{
		return -1;
	}
	int max_ = 0;
	for(int i=0;i<n;i++)
	{
		if(len[i]<=l)
		{
			int temp = solve(l-len[i],len,profit,n);
			if(temp==-1)
			{
				continue;
			}
			temp+=profit[i];
			max_ = max(temp,max_);	
		}
	}
	return max_;
}

// memorization

int solve2(int l,int* len,int* profit,int n,int* dp)
{
	if(dp[l]!=-1)
	{
		return dp[l];
	}
	if(l==0)
	{
		return 0;
	}
	if(l<0)
	{
		return -1;
	}
	int max_ = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(len[i]<=l)
		{
			int temp = solve2(l-len[i],len,profit,n,dp);
			if(temp==-1)
			{
				continue;
			}	
			temp+=profit[i];
			max_ = max(max_,temp);
		}
	}
	dp[l]=max_;
	return dp[l];
}

// iterative
int solve3(int l,int* len,int* profit,int n)
{
	int* dp = new int[l+1];
	for(int i=0;i<=l;i++)
	{
		dp[i]=-1;
	}
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		dp[len[i]]=profit[i];
	}
	for(int i=1;i<=l;i++)
	{
		
			int max_ = 0;
			int cur = i;
			for(int j=0;j<n;j++)
			{
				if((len[j] <= cur) && (cur-len[j])>=0)
				{
					int temp = dp[cur-len[j]];
					temp+=profit[j];
					max_ = max(temp,max_);
				}
			}
			dp[i]=max_;
	}
	// for(int i=0;i<=l;i++)
	// {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	int ans = dp[l];
	delete[] dp;
	return ans;
}



int main()
{
	int l;
	cin >> l;
	int n;
	cin >> n;
	int* len = new int[n];
	int* profit = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> len[i] >> profit[i];
	}
	int* dp = new int[l+1];
	for(int i=0;i<=l;i++)
	{
		dp[i]=-1;
	}

	cout << solve3(l,len,profit,n) << endl;
	delete[] dp;
	return 0;
}