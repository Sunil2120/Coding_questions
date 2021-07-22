// count all palindromic subsequences
#include<bits/stdc++.h>
using namespace std;

// recursion
int solve(string input,int i,int j)
{
	//base case
	if(i>j)
	{
		return 0;
	}
	// if i==j means single character always palindrome
	if(i==j)
	{
		return 1;
	}
	if(input[i]==input[j])
	{
		return solve(input,i+1,j)+solve(input,i,j-1)+1;
	}
	else
	{
		return solve(input,i+1,j)+solve(input,i,j-1)-solve(input,i+1,j-1);
	}
	return 0;
}

// iterative
int solve1(string input)
{
	int n = input.size();
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[n+1]();
	}
	// subsequence of length 1 is a palindrome
	for(int i=0;i<n;i++)
	{
		dp[i][i]+=1;
	}
	for(int l=2;l<=n;l++) // length of subsequence
	{
		// starting indices
		for(int i=0;i<n;i++)
		{
			//end index
			int k = l+i-1;
			if(k<n)
			{
				if(input[i]==input[k])
				{
					dp[i][k]=dp[i+1][k]+dp[i][k-1]+1;
				}
				else
				{
					dp[i][k]=dp[i+1][k]+dp[i][k-1]-dp[i+1][k-1];
				}
			}
		}
	}
	return dp[0][n-1];

}

int main()
{
	string input;
	cin >> input;
	cout << solve1(input) << endl;
	return 0;
}