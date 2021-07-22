#include<bits/stdc++.h>
using namespace std;


int solve(string input)
{
	int n = input.length();
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int left = i;
		int right = i;
		// odd length
		while(left>=0 && right<=n && input[left]==input[right])
		{
			count++;
			left--;
			right++;
		}
		// even length
		left = i;
		right = i+1;
		while(left>=0 && right<=n && input[left]==input[right])
		{
			count++;
			left--;
			right++;
		}
	}
	return count;
}
int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}