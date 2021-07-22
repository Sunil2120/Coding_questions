#include<bits/stdc++.h>
using namespace std;

bool solve(string str,set<string>& s)
{
	string output="";
	int n = str.length();
	int i=0;
	while(i < n)
	{
		output+=str[i];
		if(s.find(output)!=s.end())
		{
			//word is present
			output="";
		}
		i+=1;
	}
	if(output!="")
	{
		return false;
	}
	return true;
}
//recursion

bool solve2(string str,set<string>& s)
{
	if(str.size()==0)
	{
		return true;
	}
	if(str=="")
	{
		return true;
	}
	int n = str.size();
	for(int i=1;i<=n;i++)
	{
		if(s.find(str.substr(0,i))!=s.end())
		{
			// current prefix is present
			bool temp = solve2(str.substr(i),s);
			if(temp==true)
			{
				return true;
			}
		}
	}
	return false;
}

// iterative same as recursion using dp
bool solve3(string str,set<string>& s)
{
	int n = str.size();
	bool* dp = new bool[n+1]();// word containing first i characters
	dp[0]=true;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]==false &&  s.find(str.substr(0,i))!=s.end())// cur prefix is present in given dict
		{
			dp[i]=true;
		}
		if(dp[i]==true)// like in recursion we will check the remaining substring
		{
			if(i==n)
			{
				return true;
			}
			for(int j = i+1;j<=n;j++)
			{
				if(dp[j]==false && s.find(str.substr(i,j-i))!=s.end())
				{
					// prefix from i is present
					dp[j]=true;
				}
				if(j==n && dp[j]==true)
				{
					// remainining is present
					return true;
				}
			}
		}
	}
	delete[] dp;
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		set<string> s;
		for(int i=0;i<n;i++)
		{
			string input;
			cin >> input;
			s.insert(input);
		}
		string str;
		cin >> str;
		cout << solve3(str,s) << endl;
	}
	return 0;
}