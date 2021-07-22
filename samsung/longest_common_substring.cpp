#include<bits/stdc++.h>
using namespace std;

//Algorithm

// The longest common suffix has following optimal substructure property.

// If last characters match, then we reduce both lengths by 1
// LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1]
// If last characters do not match, then result is 0, i.e.,
// LCSuff(X, Y, m, n) = 0 if (X[m-1] != Y[n-1])

// Now we consider suffixes of different substrings ending at different indexes.
// The maximum length Longest Common Suffix is the longest common substring.
// LCSubStr(X, Y, m, n) = Max(LCSuff(X, Y, i, j)) where 1 <= i <= m and 1 <= j <= n

// time complexity O(m*n) and Auxillary space(m*n)
int solve(string x,string y,int m,int n)
{
	int** dp = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i]=new int[n+1]();
	}
	int result = INT_MIN;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=0;
			}
			result = max(result,dp[i][j]);
		}
	}
	delete[] dp;
	return result;

}


int main()
{
	string x,y;
	cin >> x >> y;
	int max_value = INT_MIN;
	cout << solve(x,y,x.size(),y.size()) << endl;
	return 0;
}