#include<bits/stdc++.h>
using namespace std;

int solve1(vector<int>& arr,int left,int right,int k)
{
	if(left > right)
	{
		return -1;
	}
	int mid = (left+right)/2;
	if(k > arr[mid])
	{
		return solve1(arr,mid+1,right,k);
	}
	else if(k < arr[mid])
	{
		return solve1(arr,left,mid-1,k);
	}
	return mid;
}

int solve2(vector<int>& arr,int n,int k)
{
	int low = 0;
	int high = n-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]==k)
		{
			return mid;
		}
		else if(k > arr[mid])
		{
			low = mid+1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int lower_bound(vector<int>& arr,int n,int k)
{
	int low = 0;
	int high = n-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid] >= k)
		{
			high = mid;
		}
		else
		{
			low = mid+1;
		}
	}
	return low;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << lower_bound(arr,n,k) << endl;
	return 0;
}