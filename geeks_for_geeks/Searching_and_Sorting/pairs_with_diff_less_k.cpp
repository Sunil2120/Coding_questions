#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr,int n,int k)
{

	int count = 0;
	if(n==0 || n==1)
	{
		return 0;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		int req = k + arr[i];
		int low = i+1;
		int high = n-1;
		int ans = -1;
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			if(arr[mid] < req)
			{
				ans = mid;
				low = mid+1;
			}
			else
			{
				high = mid-1;
			}
		}
		if(ans!=-1)
		{
			count+=(ans-(i+1)+1);
		}

	}
	return count;
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
	return 0;
}