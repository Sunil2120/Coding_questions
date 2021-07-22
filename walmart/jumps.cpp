#include<bits/stdc++.h>
using namespace std;

int solve(string input)
{
	int n = input.size();
	int* dp = new int[n];
	for(int i=0;i<n;i++)
	{
		dp[i]=-1;
	}
	int left = -1;
	for(int i=0;i<n;i++)
	{
		if(input[i]=='.')
		{
			if(left!=-1)
			{
				dp[left]=i-left;
				left = -1;
			}
			
		}
		else
		{
			if(left==-1)
			{
				left = i;
			}
		}
	}
	if(left!=-1)
	{
		dp[left]=n-left;
	}
	for(int i=0;i<n;i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	int max_window = INT_MIN;
	int max_index = -1;
	for(int i=0;i<n;i++)
	{
		if(dp[i] > max_window)
		{
			max_window = dp[i];
			max_index = i;
		}
	}
	int start_index = -1;
	int end_index = -1;
	if(max_window!=INT_MIN)
	{
		start_index = max_index;
		end_index = max_window + max_index - 1;
	}
	cout << start_index << " " << end_index << endl;
	left = start_index;
	int total = 0;
	for(int i=start_index-1;i>=0;i--)
	{
		if(dp[i]!=-1 && left >=0)
		{
			int end = dp[i]+i-1;
			total+= (dp[i]*(left-end-1));
			left = left - dp[i];

		}
	}
	int right = end_index;
	for(int i=end_index+1;i<n;i++)
	{
		if(dp[i]!=-1 && right < n)
		{
			total+=(dp[i]*(i-right-1));
			right+=dp[i];
		}
	}
	return total;

}
int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}