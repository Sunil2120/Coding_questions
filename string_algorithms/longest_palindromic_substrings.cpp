// longest palindromic substring in a given string
#include<bits/stdc++.h>
using namespace std;

int solve(string input)
{
	int max_ = INT_MIN;
	for(int i=0;i<input.length();i++)
	{
		// odd length
		int left = i;
		int right = i;
		while(left>=0 && right<input.length() && input[left]==input[right])
		{
			int count = right-left+1;
			if(count > max_)
			{
				max_ = count;
			}
			left--;
			right++;
		}
		// even length
		left = i;
		right = i+1;
		while(left>=0 && right<input.length() && input[left]==input[right])
		{
			int count = right-left+1;
			if(count > max_)
			{
				max_ = count;
			}
			left--;
			right++;
		}
	}
	return max_;
}


int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}