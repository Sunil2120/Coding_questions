#include<bits/stdc++.h>
using namespace std;

// Maximum difference of zeros and ones in binary string | Set 2 (O(n) time)
// Last Updated: 21-11-2018
// Given a binary string of 0s and 1s. The task is to find the maximum difference between the number of 0s and number of 1s in any sub-string of the given binary string. 
// That is maximize ( number of 0s – number of 1s ) for any sub-string in the given binary string.
// o(n) time and o(n) auxillary space
int kadane(int* arr,int n)
{
	int max_ = INT_MIN;
	int cur = 0;
	for(int i=0;i<n;i++)
	{
		cur+=arr[i];
		if(cur < 0)
		{
			cur = 0;
			continue;
		}
		max_ = max(max_,cur);
	}
	if(max_ == INT_MIN)
	{
		return -1;
	}
	return max_;
}
int solve(string input,int n)
{
	int* arr = new int[n]();
	// we will replace O by 1 and 1 by -1
	// required difference (0-1)
	for(int i=0;i<n;i++)
	{
		if(input[i]=='0')
		{
			arr[i]=1;
		}
		else
		{
			arr[i]=-1;
		}
	}
	// by using kadane's algorithm we will find the max sum subarray
	int ans = kadane(arr,n);
	delete[] arr;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		cout << solve(input,input.size()) << endl;
	}
	return 0;
}