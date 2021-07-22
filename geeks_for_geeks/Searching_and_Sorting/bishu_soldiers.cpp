#include<bits/stdc++.h>
using namespace std;


int getindex(vector<int>& arr,int n,int m)
{
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid]<=m)
		{
			ans = mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return ans;
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
	int sum = 0;
	vector<int> sum_arr(n,0);
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		sum_arr[i]=sum;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int m;
		cin >> m;
		int index = getindex(arr,n,m);
		cout << index+1 << " " << sum_arr[index] << endl;

	}
	return 0;
}