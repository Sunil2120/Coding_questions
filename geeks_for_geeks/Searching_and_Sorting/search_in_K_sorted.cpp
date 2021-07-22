#include<bits/stdc++.h>
using namespace std;

// Time O(logn)
int solve(vector<int>& arr,int target,int n)
{
	if(n==1)
	{
		if(target==arr[0])
		{
			return 0;
		}
		return -1;
	}
	int low = 0;
	int high = n-1;
	while(low<high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid]==target)
		{
			return mid;
		}
		else if(mid+1 < n && arr[mid+1]==target)
		{
			return mid+1;
		}
		else if(mid-1>=0 && arr[mid-1]==target)
		{
			return mid-1;
		}
		if(target < arr[mid])
		{
			high = mid-2;
		}
		else
		{
			low = mid+2;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int target;
	cin >> target;
	cout << solve(arr,target,n) << endl;
	return 0; 
}