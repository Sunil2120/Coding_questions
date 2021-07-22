// printing lcs 
// printing the longest palindromic subsequence
// just reverse the given string and find lcs and print it

#include<bits/stdc++.h>
using namespace std;

int lcs(string first,string second)
{
	int m = first.size();
	int n = second.size();
	int** dp = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i] = new int[n+1]();
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(first[i-1]==second[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans = dp[m][n];
	int i=m;
	int j=n;
	string output="";
	while(i>0 && j>0)
	{
		if(first[i-1]==second[j-1])
		{
			output = first[i-1]+output;
			i--;
			j--;
		}
		else
		{
			if(dp[i][j]==dp[i-1][j])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	cout << output << endl;
	delete[] dp;
	return ans;
}

int main()
{
	string first;
	cin >> first;
	string second = first;
	reverse(second.begin(),second.end());
	// cin >> second;
	cout << lcs(first,second) << endl;
	return 0;
}