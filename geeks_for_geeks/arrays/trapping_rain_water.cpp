#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//O(n) and O(n) auxillary space
int solve(vector<int>& arr,int n)
{
	int left[n];
	int right[n];
	for(int i=0;i<n;i++)
	{
		left[i]=INT_MIN;
		right[i]=INT_MIN;
	}
	left[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		left[i]=max(left[i-1],arr[i]);
	}
	right[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		right[i]=max(right[i+1],arr[i]);
	}
	int total = 0;
	for(int i=0;i<n;i++)
	{
		total+=(min(left[i],right[i])-arr[i]);
	}
	return total;
	
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
	cout << solve(arr,n) << endl;
	return 0;
}