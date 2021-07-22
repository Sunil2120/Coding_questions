#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr,int n,int k)
{
	int total = 0;
	if(n==0 || k==0)
	{
		return 0;
	}
	int mid = ceil(n/2.0);
	int i=0;
	int j=(n*k);
	int left = mid-1;
	int right = n-left;
	j=j-right;
	while(i<n && j>=0 && i<=j)
	{
		total+=arr[j];
		j-=right;
		i+=left;
	}
	return total;

}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n*k);
	for(int i=0;i<n*k;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
	return 0;

}