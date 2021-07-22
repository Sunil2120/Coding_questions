#include<iostream>
#include<string>
using namespace std;


bool solve(string input,string pattern)
{
	int m = input.size();
	int n = pattern.size();
	//dp[i][j] represents the whether first i characters and first j characters are same or not
	bool** dp = new bool*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i]=new bool[n+1]();
	}
	dp[0][0]=true;
	for(int i=1;i<=m;i++)
	{
		dp[i][0]=false;
	}
	for(int i=1;i<=n;i++)
	{
		if(pattern[i-1]=='*')
		{
			dp[0][i]=dp[0][i-1];
		}
	}
	//i->input
	// j->pattern
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(input[i-1]==pattern[j-1] || pattern[j-1]=='?')
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else if(pattern[j-1]=='*')
			{
				dp[i][j]=dp[i][j-1]||dp[i-1][j];
			}
			else if(input[i-1]!=pattern[j-1])
			{
				dp[i][j]=false;
			}
		}
	}
	return dp[m][n];
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		string pattern;
		cin >> pattern;
		cout << solve(input,pattern) << endl;
	}
	return 0;
}