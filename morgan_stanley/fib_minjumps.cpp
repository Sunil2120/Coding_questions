#include<bits/stdc++.h>
using namespace std;


bool isperfectsquare(int value)
{
	int x = sqrt(value);
	if((x*x) == value )
	{
		return true;
	}
	return false;
}
bool isfibonacci(int value)
{
	return isperfectsquare(5*value*value + 4) || isperfectsquare(5*value*value - 4);
}

int solve(vector<int>& input,int n)
{
	int*dp = new int[n+2];
	input.push_back(1);
	for(int i=0;i<n+2;i++)
	{
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	for(int i=1;i<n+2;i++)
	{
		if(input[i]==1)
		{
			for(int j=0;j<i;j++)
			{
				if(input[j]==1 && isfibonacci(i-j)==true && dp[j]!=INT_MAX)
				{
					dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
	}
	return dp[n+1];

}

int main()
{
	int n;
	cin >> n;
	vector<int> input;
	input.push_back(1);
	for(int i=0;i<n;i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	cout << solve(input,n) << endl;
	return 0;
}