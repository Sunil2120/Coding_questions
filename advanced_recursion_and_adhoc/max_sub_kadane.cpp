#include<bits/stdc++.h>
using namespace std;

int kadane(int* arr,int n)
{
	int max_= 0;
	int cur = 0;
	for(int i=0;i<n;i++)
	{
		cur+=arr[i];
		if(cur < 0)
		{
			cur = 0;
		}
		if(cur > max_)
		{
			max_ = cur;
		}
	}
	return max_;
}


int solve(int* arr,int n)
{
	int total_sum = 0;
	int max_sum = 0;
	int min_sum = 0;
	// without wrapping
	max_sum = kadane(arr,n);
	// with wrapping
	// total sum - min_sum subarray
	for(int  i=0;i<n;i++)
	{
		total_sum+= arr[i];
		arr[i] = -1*arr[i];
	}
	min_sum = kadane(arr,n);
	int max_sum2 = total_sum - (-1*min_sum);
	return max(max_sum2,max_sum);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
	}
}