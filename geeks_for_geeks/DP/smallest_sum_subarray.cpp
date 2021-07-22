#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int n)
{
	int cur = 0;
	int max_value = INT_MIN;
	int left =0;
	int left_max = -1;
	int right_max = -1;
	for(int i=0;i<n;i++)
	{
		cur+=arr[i];
		if(cur > max_value)
		{
			max_value = cur;
			left_max = left;
			right_max = i;
		}
		if(cur < 0)
		{
			cur = 0;
			if(i+1 < n)
			{
				left = i+1;
			}
		}
	}
	for(int i=left_max;i<=right_max;i++)
	{
		cout << arr[i]*-1 << " ";
	}
	cout << endl;
	return -1*max_value;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=-1*arr[i];
	}
	cout << solve(arr,n) << endl;
	return 0;
}