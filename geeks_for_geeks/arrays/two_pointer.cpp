// two pointer algo is used to pair of elements in the given array to whose sum is equal to given sum
#include<bits/stdc++.h>
using namespace std;


bool solve(int* arr,int n,int k)
{
	sort(arr,arr+n);
	int first = 0;
	int last = n-1;
	while(first!=last && first < n && last >=0)
	{
		int sum = arr[last]+arr[first];
	
		if(sum==k)
		{
			cout << arr[first] << " " << arr[last] << endl;
			return true;
		}
		else if(sum > k)
		{
			// decrement the last
			last = last-1;
		}
		else 
		{
			// increament the first
			first = first+1;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int k=0;
	cin >> k;
	cout << solve(arr,n,k) << endl;
}