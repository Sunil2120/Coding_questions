#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int n,int k)
{
	sort(arr,arr+n);
	
	int min_ = INT_MAX;
	for(int i=n-1;i>=0;i--)
	{
		int total_removal = 0;
		for(int j=0;j<n;j++)
		{
			if((arr[i]-arr[j]) <= k)
			{
				total_removal+=(j);
				break;
			}
		}
		total_removal+=(n-1-i);
		min_ = min(total_removal,min_);
	}
	return min_;
}

int main()
{
	int n,k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
	return 0;
}