#include<bits/stdc++.h>
using namespace std;

// time complexity O(n+k)
int solve(vector<int>& arr,int n,int k)
{
	int* rem = new int[k]();
	int cur_sum = 0;
	for(int i=0;i<n;i++)
	{
		cur_sum+=arr[i];
		rem[(cur_sum%k + k)%k]+=1;// cur_sum can be negative
	}
	int count = 0;
	for(int i=0;i<k;i++)
	{
		if(rem[i] > 1)
		{
			count+=(rem[i]*(rem[i]-1))/2;
		}
	}
	count+=rem[0];
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