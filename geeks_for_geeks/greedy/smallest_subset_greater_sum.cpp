#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr,int n)
{
	sort(arr.begin(),arr.end());
	int count = 0;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	int temp = 0;
	for(int i=n-1;i>=0;i--)
	{
		temp+=arr[i];
		count+=1;
		int rem = sum - temp;
		if(temp > rem)
		{
			return count; 
		}
	}
	return count;
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