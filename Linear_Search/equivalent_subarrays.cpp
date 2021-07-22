#include<bits/stdc++.h>
using namespace std;

//Given an array arr[] of n integers. 
//Count the total number of sub-array having total distinct elements same as that of total distinct elements of the original array.
// if at a particular index if the distinct elements is equal to distinct elements of the array
// then the ans = (n-(r+1)+1)
// we will use sliding window approach
int solve(vector<int>& arr,int n,int distinct)
{
	int left = 0;
	int r = 0;
	unordered_map<int,int> hash;
	int count = 0;
	int temp = 0;
	while(r < n)
	{
		if(hash[arr[r]]==0)
		{
			temp+=1;
		}
		hash[arr[r]]+=1;
		if(temp==distinct)
		{
			count+=(n-r-1+1);
			while(left <= r && temp==distinct)
			{
				hash[arr[left]]--;
				if(hash[arr[left]]==0)
				{
					temp--;
				}
				if(temp==distinct)
				{
					count+=(n-r-1+1);
				}
				left++;
			}
		}
		r+=1;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	unordered_map<int,int> hash;
	int  distinct = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(hash[arr[i]]==0)
		{
			distinct+=1;
		}
		hash[arr[i]]+=1;
	}
	cout << solve(arr,n,distinct) << endl;
	return 0;
}