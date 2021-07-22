#include<bits/stdc++.h>
using namespace std;


void solve2(bool** dp,string input,string temp,int x,vector<string>& output)
{
	if(x==input.size())
	{
		output.push_back(temp);
		return ;
	}
	for(int i=x;i<input.size();i++)
	{
		if(dp[x][i]==true)
		{
			string temp2 = temp+ input.substr(x,i-x+1)+" ";
			solve2(dp,input,temp2,i+1,output);
		}
	}
	return ;
}

void solve(string input)
{
	int n = input.size();
	bool** dp = new bool*[n];
	for(int i=0;i<n;i++)
	{
		dp[i]=new bool[n]();
	}
	for(int g=0;g<n;g++)
	{
		for(int i=0,j=g;j<n;i++,j++)
		{
				if(g==0)
				{
					dp[i][j]=true;
				}
				else if(g==1)
				{
					if(input[i]==input[j])
					{
						dp[i][j]=true;
					}
				}
				else
				{
					if(input[i]==input[j] && dp[i+1][j-1]==true)
					{
						dp[i][j]=true;
					}
				}
		}
	}
	vector<string> output;
	for(int i=0;i<n;i++)
	{
		if(dp[0][i]==true)
		{
			string temp=input.substr(0,i+1) + " ";
			solve2(dp,input,temp,i+1,output);
		}
	}
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << endl;
	}
	return ;
}
int main()
{
	string input;
	cin >> input;
	solve(input);
	return 0;
}