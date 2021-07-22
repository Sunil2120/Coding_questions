// same as aggressive cows problem(binary search)
// time complexity  binary_search logn * check_func n => o(nlog(n)) => n(max(arr)-min(arr))
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr,int n,int m,int val)
{
	// we will place the first ball at arr[0] basket
	int position = arr[0];
	int count = 1;
	for(int i=1;i<n;i++)
	{
		if((arr[i] - position) >= val)// dist b/w cur and prev basket is atleast val
		{
			count+=1;
			position = arr[i];
			if(count==m)
			{
				return true;
			}
		}
	}
	return false;
}

int solve(vector<int>& arr,int n,int m)
{

	sort(arr.begin(),arr.end());
	// magnetic force b/w two balls can be 0 <= force <= (arr[n-1]-arr[0])
	// we will check one by one if for a particular force if it is possible to place all m balls
	int start = 0;
	int end = arr[n-1] - arr[0];
	// we will check for mid if it possible for mid we will check further else
	// we will check below mid
	// binary search
	int ans = 0;
	while(start<=end)
	{
		int mid = (start + end)/2;
		if(check(arr,n,m,mid)==true)
		{
			ans = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}

	}
	return ans;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int value;
		cin >> value;
		arr.push_back(value);
	}
	cout << solve(arr,n,m) << endl;
	
}