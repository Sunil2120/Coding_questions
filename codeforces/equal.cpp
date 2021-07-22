#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n)
{
	int max_value = arr[0];
	for(int i=1;i<n;i++)
	{
		max_value = max(max_value,arr[i]);
	}
	int total = 0;
	for(int i=0;i<n;i++)
	{
		total+=(max_value - arr[i]);
	}
	return abs(max_value - total);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
	}
	return 0;
}