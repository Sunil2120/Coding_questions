#include<bits/stdc++.h>
using namespace std;

// we don't know  how may elements arr contains it may have infinite number of elements
//	elements are sorted
int solve(int arr[101],int target)
{
	int low=0;
	int high=1;
	// we don't know the bounds
	// we will first find the higher bound
	while(target > arr[high])// my required elements is still right of high
	{
		low = high;//since high is less than target it can be my lower bound
		// to find the element lower bound doesn't matter
		// less the window size to check less the time taken to find the element
		high = high*2;
	}
	// now arr[high] > target
	//just we will apply binary search
	// we know the bounds
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid]==target)
		{
			return mid;
		}
		else if(target > arr[mid])
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return -1;

}

int main()
{

	int arr[101]={1,2,3,4,5,6,7,8,9,10};
	int target;
	cin >> target;
	cout << solve(arr,target) << endl;
	return 0;
}