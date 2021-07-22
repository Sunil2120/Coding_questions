#include<bits/stdc++.h>
using namespace std;


int solve(string input,int low,int high)
{
	if(low > high)
	{
		return INT_MAX;
	}
	if(low==high)
	{
		return 0;
	}
	if(high-low+1 == 2)
	{
		if(input[low]==input[high])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if(input[low]==input[high])
	{
		return solve(input,low+1,high-1);
	}
	return min(solve(input,low+1,high),solve(input,low,high-1))+1;
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input,0,input.size()-1) << endl;
	return 0;
}