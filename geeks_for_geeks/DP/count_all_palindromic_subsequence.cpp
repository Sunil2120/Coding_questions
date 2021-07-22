// Count all palindromic subsequence
#include<bits/stdc++.h>
using namespace std;


// recursion
int solve(string input,int i,int j)
{
	if(i > j)
	{
		return 0;// invalid
	}
	if(i==j)
	{
		return 1;
	}
	if(input[i]==input[j])
	{
		return 1 + solve(input,i+1,j) + solve(input,i,j-1);
	}
	return solve(input,i+1,j)+solve(input,i,j-1)-solve(input,i+1,j-1);
}

// dp
int solve2(string input)
{
	int n = input.size();
	int** dp = new int*[n];
	for(int i=0;i<n;i++)
	{
		dp[i]=new  int[n]();
	}
	// if only one character return 1
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
	}
	for(int l=2;l<=n;l++)// length
	{
		// starting indices
		for(int i=0;i<n;i++)
		{
			// l = k-i+1
			int k = l+i-1;
			if(k < n)
			{
				if(input[i]==input[k])
				{
					dp[i][k]=1+dp[i+1][k]+dp[i][k-1];
				}
				else
				{
					dp[i][k]=dp[i+1][k]+dp[i][k-1]-dp[i+1][k-1];
				}
			}
		}
	}
	int ans = dp[0][n-1];
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