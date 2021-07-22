#include<bits/stdc++.h>
using namespace std;

// recursion
int solve(string input,int i,int j)
{
	if(i > j)
	{
		return 0;// invalid case
	}
	if(i==j)// only one character
	{
		return 1;
	}
	if(input[i]==input[j] && (j-i+1)==2)//only 2 characters
	{
		return 2;
	}
	if(input[i]==input[j])
	{
		return 2 + solve(input,i+1,j-1);
	}
	return max(solve(input,i,j-1),solve(input,i+1,j));
}

// dp
int solve2(string input)
{
	int n = input.size();
	int** dp = new int*[n];
	// dp stores the longest palindromic subsequence from ith index to jth index
	for(int i=0;i<n;i++)
	{
		dp[i]=new int[n]();
	}
	// if only one character
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
	}
	for(int l=2;l<=n;l++)//length
	{
		for(int i=0;i<n;i++)// starting indices
		{
			// l = k-i+1
			int k = l+i-1;
			if(k < n)
			{
				if(input[i]==input[k] && l==2)
				{
					dp[i][k]=2;
					continue;
				}
				if(input[i]==input[k])
				{
					dp[i][k]=dp[i+1][k-1]+2;
				}
				else
				{
					dp[i][k]=max(dp[i+1][k],dp[i][k-1]);
				}	
			}
		}
	}
	int ans = dp[0][n-1];// longest palindromic subsequence in whole string
	delete[] dp;
	return ans;
}


int main()
{
	string input;
	cin >> input;
	cout << solve(input,0,input.size()-1) << endl;
	cout << solve2(input) << endl;
	return 0;
}