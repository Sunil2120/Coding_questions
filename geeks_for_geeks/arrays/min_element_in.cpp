// given an array we should find the min_element in o(log n)
// we are using binary search

// A simple solution is to traverse the complete array and find minimum. This solution requires O(n) time.
// We can do it in O(Logn) using Binary Search. If we take a closer look at above examples, we can easily figure out following pattern:

// The minimum element is the only element whose previous is greater than it. If there is no previous element element, then there is no rotation (first element is minimum). We check this condition for middle element by comparing it with (mid-1)’th and (mid+1)’th elements.
// If minimum element is not at middle (neither mid nor mid + 1), then minimum element lies in either left half or right half.
// If middle element is smaller than last element, then the minimum element lies in left half
// Else minimum element lies in right half.
#include<bits/stdc++.h>
using namespace std;

int find_min(int* arr,int start,int end)
{
	if(start > end)
	{
		return arr[0];
	}
	if(start==end)
	{
		return arr[start];
	}
	int mid = start + (end-start)/2;
	// checking mid
	if(mid > start && arr[mid-1] > arr[mid])
	{
		// mid is the min_element
		return arr[mid];
	}

	if(mid < end && arr[mid] > arr[mid+1])
	{
		return arr[mid+1];
	}
	// we will go left if everything in right is fine and vice versa
	if(mid < end && arr[mid] < arr[end])
	{
		return find_min(arr,start,mid-1);// everthing in right is fine so we are going left
	}
	// if not going right
	if(mid < end && arr[end] < arr[mid])
	{
		return find_min(arr,mid+1,end);
	}
	return 0;
	
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
		cout << find_min(arr,0,n-1) << endl;
		delete[] arr;
	}
	
}