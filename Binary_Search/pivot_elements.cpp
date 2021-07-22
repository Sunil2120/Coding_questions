#include<bits/stdc++.h>
using namespace std;


int max_pivot(vector<int>& arr,int n)
{
	int low = 0;
	int high = n-1;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		// we will check whether mid is the pivot element or not
		if(mid+1 < n && arr[mid] > arr[mid+1])
		{
			// mid is the pivot element
			return mid;
		}
		// we have checked right so we will check left
		if(mid-1 >=0 && arr[mid-1] > arr[mid])
		{
			// mid-1 is the pivot element
			return mid-1;
		}
		// if both left and right is fine 
		// if everything is sorted(correct) in right we will go left otherwise right
		if(arr[mid] < arr[high])//sorted
		{
			high = mid-1;//left
		}
		else
		{
			low = mid+1;//right
		}
	}
	return -1;
}


int min_pivot(vector<int>& arr,int n)
{
	int low = 0;
	int high = n-1;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		// check whether mid is the pivot element or not
		if(mid-1 >=0 && arr[mid] < arr[mid-1])
		{
			return mid;
		}
		if(mid+1 < n && arr[mid] > arr[mid+1])
		{
			return mid+1;
		}
		if(arr[mid] < arr[high])
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
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
	cout << max_pivot(arr,n) << endl;
	cout << min_pivot(arr,n) << endl;
}