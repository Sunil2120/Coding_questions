#include<bits/stdc++.h>
using namespace std;

int findpivot(vector<int>& arr,int low,int high)
{
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(mid<high && arr[mid] > arr[mid+1])
		{
			return mid;
		}
		if(mid > 0 && arr[mid-1] > arr[mid])
		{
			return mid-1;
		}
		if(mid < high && arr[mid] < arr[high])
		{
			//left
			high = mid-1;
		}
		else if(mid > low && arr[mid] > arr[low])
		{
			//right
			low = mid+1;
		}
	}
	return -1;
}
int solve(vector<int>& arr,int n,int k)
{
	int low = 0;
	int high = n-1;
	int check = 0;
	while(low<=high)
	{
		if(check==0)
		{
			int pivot = findpivot(arr,low,high);
			cout << pivot << endl;
			if(arr[pivot]==k)
			{
				return pivot;
			}

			if(k>=arr[low])
			{
				high = pivot-1;
			}
			else
			{
				low = pivot+1;
			}
			check = 1;
			continue;
		}
		int mid = low+(high-low)/2;
		if(arr[mid]==k)
		{
			return mid;
		}
		if(k < arr[mid])
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
	int k;
	cin >> k;
	cout << solve(arr,n,k) << endl;
	return 0;
}