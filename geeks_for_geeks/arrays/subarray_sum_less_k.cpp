#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

int solve(vector<int>& arr,int n,int k)
{
	if(n==0)
	{
		return 0;
	}
	int left = 0;
	int right = 0;
	int cur = 0;
	int output=INT_MAX;
	while(right < n)
	{
		cur+=arr[right];
		while(cur>k && left <= right)
		{
			output = min(output,right-left+1);
			cur = cur - arr[left];
			left+=1;
		}
		right+=1;
	}
	return output;
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