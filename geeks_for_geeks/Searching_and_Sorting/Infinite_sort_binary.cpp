#include<bits/stdc++.h>
using namespace std;


int solve(string input)
{
	int low=0;
	int high = 1;
	while(input[high]=='0')
	{
		low = high;
		high=high*2;
	}

	int ans=-1;
	while(low<=high)
	{
		int mid = (low) + (high-low)/2;
		if(input[mid]=='0')
		{
			low = mid+1;
		}
		else
		{
			ans = mid;
			high = mid-1;
		}
	}
	return ans;
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}