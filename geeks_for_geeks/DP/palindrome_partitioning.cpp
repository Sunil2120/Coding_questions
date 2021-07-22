#include<bits/stdc++.h>
using namespace std;



bool isPalindrome(string s,int i,int j)
{
	while(i<j)
	{
		if(s[i]!=s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int solve(string s,int i,int j)
{
	
	if(i==j)
	{
		return 0;
	}
	if(i+1==j)
	{
		if(s[i]==s[j])
		{
			return 0;
		}
		return 1;
	}
	if(isPalindrome(s,i,j))
	{
		return 0;
	}
	int min_value = 99999;
	for(int k=i;k<j;k++)
	{
		int temp = solve(s,i,k)+solve(s,k+1,j)+1;
		min_value = min(min_value,temp);
	}
	return min_value;
}

int solve2(string s)
{
	bool** palindrome=new bool*[s.size()];
	for(int i=0;i<s.size();i++)
	{
		palindrome[i]=new bool[s.size()]();
	}
	for(int g=0;g<s.size();g++)
	{
		for(int i=0,j=g;j<s.size();i++,j++)
		{
			if(g==0)
			{
				//one character
				palindrome[i][j]=true;
			}
			else if(g==1)
			{
				//two character
				if(s[i]==s[j])
				{
					palindrome[i][j]=true;
				}
				else
				{
					palindrome[i][j]=false;
				}
			}
			else
			{
				if(s[i]==s[j] && palindrome[i+1][j-1]==true)
				{
					palindrome[i][j]=true;
				}
				else
				{
					palindrome[i][j]=false;
				}
			}
		}
	}
	int** dp = new int*[s.size()];
	for(int i=0;i<s.size();i++)
	{
		dp[i]=new int[s.size()]();
	}
	for(int g=0;g<s.size();g++)
	{
		for(int i=0,j=g;j<s.size();i++,j++)
		{
			if(g==0)
			{
				dp[i][j]=0;
			}
			else if(g==1)
			{
				if(s[i]==s[j])
				{
					dp[i][j]=0;
				}
				else
				{
					dp[i][j]=1;
				}
			}
			else
			{
				if(palindrome[i][j]==true)
				{
					dp[i][j]=0;
				}
				else
				{
					int min_value=INT_MAX;
					for(int k=i;k<j;k++)
					{
						min_value = min(min_value,dp[i][k]+dp[k+1][j]+1);
					}
					dp[i][j]=min_value;
				}
			}
		}
	}
	return dp[0][s.size()-1];
}

int solve3(string s)
{
	bool** palindrome=new bool*[s.size()];
	for(int i=0;i<s.size();i++)
	{
		palindrome[i]=new bool[s.size()]();
	}
	for(int g=0;g<s.size();g++)
	{
		for(int i=0,j=g;j<s.size();i++,j++)
		{
			if(g==0)
			{
				//one character
				palindrome[i][j]=true;
			}
			else if(g==1)
			{
				//two character
				if(s[i]==s[j])
				{
					palindrome[i][j]=true;
				}
				else
				{
					palindrome[i][j]=false;
				}
			}
			else
			{
				if(s[i]==s[j] && palindrome[i+1][j-1]==true)
				{
					palindrome[i][j]=true;
				}
				else
				{
					palindrome[i][j]=false;
				}
			}
		}
	}

	int* dp = new int[s.size()];
	dp[0]=0;
	dp[1]=(s[0]==s[1])?0:1;
	for(int i=2;i<s.size();i++)
	{
		if(palindrome[0][i]==true)
		{
			dp[i]=0;
		}
		else
		{
			int min_value=INT_MAX;
			for(int j=i;j>0;j--)
			{
				if(palindrome[j][i]==true)
				{
					min_value=min(min_value,dp[j-1]+1);
				}
			}
			dp[i]=min_value;
		}
	}
	return dp[s.size()-1];
}

int main()
{
	string s;
	cin >> s;
	cout << solve(s,0,s.size()-1) << endl;
	cout << solve2(s) << endl;
	cout << solve3(s) << endl;
	return 0;
}