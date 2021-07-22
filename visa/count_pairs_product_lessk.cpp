#include<bits/stdc++.h>
using namespace std;

//O(nlogn) time
int solve(vector<int>&  arr,int n,int k)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int low = i+1;
		int high = n-1;
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			if(arr[mid]*arr[i] <= k)
			{
				count+=(mid-low)+1;
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
	}
	return count;
}
//O(n)
//samething goes with find the pairs whose sum is less than k
int solve2(vector<int>& arr,int n,int k)
{
	int count = 0;
	//should be sorted
	int low = 0;
	int high = n-1;
	while(low<high)
	{
		if(arr[low]*arr[high] <= k)
		{
			count+=(high-low);
			low+=1;
		}
		else
		{
			high-=1;
		}
	}
	return count;
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
	int k;
	cin >> k;
	cout << solve(arr,n,k) << endl;
	cout << solve2(arr,n,k) << endl;
	return 0;
}