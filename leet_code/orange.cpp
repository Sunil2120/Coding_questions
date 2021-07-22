#include<bits/stdc++.h>
using namespace std;


int solve(int n,unordered_map<int,int>& hash)
{
	if(n==0)
	{
		return 0;
	}

	int temp1 = INT_MAX;
	if(hash[n-1]!=0)
	{
		temp1 = hash[n-1];
	}
	else
	{
		temp1 = solve(n-1,hash);
	}
	int temp2 = INT_MAX;
	if((n%2)==0)
	{
		if(hash[n/2]!=0)
		{
			temp2 = hash[n/2];
		}
		else
		{
			temp2 = solve(n/2,hash);
		}
		
	}
	int temp3 = INT_MAX;
	if((n%3)==0)
	{
		int index = n - 2*(n/3);
		if(hash[index]!=0)
		{
			temp3 = hash[index];
		}
		else
		{
			temp3 = solve(n,hash);
		}
		
	}
	int ans = min(temp1,min(temp2,temp3))+1;
	hash[n]= ans;
	return ans;
}

// o(N) time
int solve1(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n<0)
	{
		return INT_MAX;
	}
	int temp1 = INT_MAX;
	int temp2 = INT_MAX;
	int temp3 = INT_MAX;
	temp1 = solve1(n-1);
	if((n%2)==0)
	{
		temp2 = solve1(n/2);
	}
	if((n%3)==0)
	{
		int index = n - 2*(n/3);
		temp3 = solve1(index);
	}
	return min(temp1,min(temp2,temp3))+1;
}

// o(log^2 N)
int solve3(int n)
{
	if(n==0 || n==1 || n==2)
	{
		return n;
	}
	return 1 + min(n%2 + solve3(n - n/2),n%3 + solve3(n - 2*n/3));
}

int solve4(int n,int* dp)
{
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	if(n==0 || n==1 || n==2)
	{
		return n;
	}
	dp[n] = 1 + min(n%2 + solve4(n/2,dp),n%3 + solve4(n/3,dp));
	return dp[n];
}




int main()
{
	int n;
	cin >> n;
	unordered_map<int,int> hash;
	int* dp = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	cout << solve1(n) << endl;
	cout << solve4(n,dp) << endl;
	delete[] dp;
	return 0;
}