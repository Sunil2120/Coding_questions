#include<bits/stdc++.h>
using namespace std;


// Trailing 0s in n! = Count of 5s in prime factors of n!
//                   = floor(n/5) + floor(n/25) + floor(n/125) + ....

// Given a number n. 
// The task is to find the smallest number whose factorial contains at least n trailing zeroes.


bool ispossible(int mid,int n)
{
	int count = 0;
	for(int i=5;(mid/i)>=1;i=i*5)
	{
		count+=(mid/i);
	}
	if(count >= n)// atleast n zeros
	{
		return true;
	}
	return false;
}
int solve(int n)
{
	int low = 1;
	int high = 1000000;
	int ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(ispossible(mid,n))
		{
			ans = mid;
			// we need the smallest number
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}