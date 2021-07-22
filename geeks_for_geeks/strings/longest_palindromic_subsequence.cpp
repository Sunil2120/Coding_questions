// find the longest palindromic subsequence
// we will use lcs algo
// we will reverse the given string
// then we will find the lcs which is nothing but longest palindromic subsequence
#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solve(string input,int i,int j)
{
	if(i==j)
	{
		return 1;//one char
	}
	if(input[i]==input[j] && (j-i+1)==2)//only 2 char and are equal
	{
		return 2;
	}
	if(input[i]==input[j])
	{
		return 2 + solve(input,i+1,j-1);//shrink
	}
	return max(solve(input,i,j-1),solve(input,i+1,j));
}

//same thing as recursive but iterative approach
int solve2(string input,int n)
{
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[n+1]();
	}
	for(int i=0;i<n;i++)
	{
		dp[i][i]+=1;//only 1 char
	}
	for(int l=2;l<=n;l++)// length of strings
	{
		for(int i=0;i<n;i++)//starting indices
		{
			int k = l+i-1;// ending indices
			if(k<n)
			{
				if(input[i]==input[k] && l==2)
				{
					dp[i][k]=2;
					continue;
				}
				if(input[i]==input[k])
				{
					dp[i][k] = 2 + dp[i+1][k-1];//shrink
				}
				else
				{
					dp[i][k]=max(dp[i+1][k],dp[i][k-1]);
				}

			}
			
		}
	}
	int ans = dp[0][n-1];
	for(int i=0;i<=n;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;

}


int main()
{
	string input;
	cin >> input;
	int n = input.size();
	cout << solve(input,0,n-1) << endl;
	cout << solve2(input,n) << endl;
}