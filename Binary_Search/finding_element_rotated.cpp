#include<bits/stdc++.h>
using namespace std;

// finding the particular element in sorted rotated array using binary search.

// steps
//1. we will check whether mid is the required element
//2. if mid is not the key,if left of mid is sorted and key lies in that left part we will go left else right
//3. if left is not sorted obviously right will be sorted so go right and check whether key
// lies in that part if not go left


int solve(vector<int>& arr,int n,int key)
{
	int low = 0;
	int high = n-1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		// we will check left part is sorted or not
		if(arr[low] <= arr[mid])
		{
			if(key >= arr[low] && key < arr[mid])// key lies in this range
			{
				// we will go left
				high= mid-1;
			}
			else
			{
				low = mid+1;// we will go right
			}
		}
		else 
		{
			// if left is not sorted definitely right is sorted
			if(key > arr[mid] && key <= arr[high])
			{
				low = mid+1;//right
			}
			else
			{
				high = mid-1;//left
			}
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
	int key;
	cin >> key;
	cout << solve(arr,n,key) << endl;
	return 0;
}