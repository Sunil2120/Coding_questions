#include<bits/stdc++.h>
using namespace std;

// Given an array that represents elements of arithmetic progression in order. 
// One element is missing in the progression, find the missing number.

int solve(vector<int>& arr,int n)
{
	// we should find the missing number
	int low = 0;
	int high = n-1;
	int diff = (arr[0]+arr[n-1])/n;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if( mid+1 < n && (arr[mid+1]-arr[mid])!=diff)
		{
			return arr[mid]+diff;
		}
		if(mid-1 >=0 && (arr[mid]-arr[mid-1])!=diff)
		{
			return arr[mid]-diff;
		}
		// if everything is fine in left we will
		// search the  missing element in right
		if(arr[mid]==arr[0]+(mid)*diff)
		{
			low = mid+1;//right
		}
		else
		{
			high = mid-1;//left;
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
	cout << solve(arr,n) << endl;
	return 0;
}