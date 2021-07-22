#include<bits/stdc++.h>
using namespace std;

// recursion
int min_edits(string first,string second)
{
	if(first.length()==0 || second.length()==0)
	{
		if(first.length()==0)// we should insert second.length() number of characters
		{
			return second.length();
		}
		else
		{
			// second is empty we should delete remaining char in first
			return first.length();
		}
	}
	if(first[0]==second[0])
	{
		return min_edits(first.substr(1),second.substr(1));
	}
	else
	{
		// insertion
		int ins = 1 + min_edits(first,second.substr(1));
		// delete
		int del = 1 + min_edits(first.substr(1),second);
		// sub
		int sub = 1 + min_edits(first.substr(1),second.substr(1));
		// we need min_steps
		return min(ins,min(del,sub));
	}
	return -1;
}

// iterative
int min_edits1(string first,string second)
{
	int m = first.size();
	int n = second.size();
	int** dp = new int*[m+1];
	// dp[i][j] steps required for i size of first and j size of second
	for(int i=0;i<=m;i++)
	{
		dp[i]=new int[n+1]();
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=i;
	}
	for(int i=0;i<=m;i++)
	{
		dp[i][0]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(first[m-i]==second[n-j])
			{
				dp[i][j]=dp[i-1][j-1];//if equal
			}
			else
			{
				// insert
				int ins = dp[i][j-1];
				// delete
				int del = dp[i-1][j];
				// substitue
				int sub = dp[i-1][j-1];
				dp[i][j]=min(ins,min(del,sub))+1;
			}
		}
	}
	int ans = dp[m][n];
	for(int i=0;i<=m;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int main()
{
	string first,second;
	cin >> first >> second;
	cout << min_edits(first,second) << endl;
	cout << min_edits1(first,second) << endl;
	return 0;
}