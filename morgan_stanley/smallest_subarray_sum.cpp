#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n,int key)
{
	int left = 0;
	int right = 0;
	int sum = 0;
	int min_value = INT_MAX;
	while(right < n)
	{
		sum+=arr[right];
		if(sum > key)
		{
			while(sum > key && left <= right)
			{
				sum-=arr[left];
				left++;
			}
			if(sum <= key)
			{
				sum+=arr[left-1];
				left-=1;
				min_value = min(min_value,right-left+1);	
			}
		}
		right+=1;
	}
	return min_value;
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
	int key;
	cin >> key;
	cout << solve(arr,n,key) << endl;
	return 0;
}