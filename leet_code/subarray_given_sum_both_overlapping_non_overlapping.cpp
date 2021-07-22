#include<bits/stdc++.h>
using namespace std;

// refer techdose youtube channel

// overlapping


// O(n2) method and o(1) auxillary space

int solve(int* arr,int n,int k)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i]=sum;
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int cur =arr[i];
		if(arr[i]==k)// zero is not present
		{
			count+=1;
			continue;
		}
		int val = arr[i]-k;// prefix_sum - val = k => prefix_sum - k = val
		for(int j=0;j<i;j++)
		{
			if(arr[j]==val)
			{
				count+=1;
			}
		}
	}
	return count;
}


// o(n) and o(n) auxillary space
int solve2(int* arr,int n,int k)
{
	unordered_map<int,int> hash;
	int sum = 0;
	int count = 0;
	hash[0]=1;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];// prefix sum
		int val = sum - k;// prefix_sum - val = k => prefix_sum - k = val
		if(hash[val]!=0)// present(previously occured)
		{
			count+=1;
		}
		hash[sum]+=1;
	}
	return count;
}

// non overlapping
// o(n^2) and o(1) auxillary space
int solve3(int* arr,int n,int k)
{
	int sum = 0;
	int start = 0;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i]=sum;
		if(arr[i]==k)
		{
			count+=1;
			start = i+1;//avoiding overlapping
			// to avoid overlapping we start checking from start
			// so no need of making sum = 0
			sum = 0;
		}
		int val = arr[i]-k;
		for(int j=start;j<i;j++)
		{
			if(arr[j]==val)
			{
				count+=1;
				start = i+1;
				sum = 0;
				// to avoid overlapping we start checking from start
				// so no need of making sum = 0
				break;
			}
		}
	}
	return count;
}

// non overlapping o(n) time and o(n) auxillary space
int solve4(int* arr,int n,int k)
{
	unordered_map<int,int> hash;
	int sum = 0;
	int count = 0;
	hash[0]=1;// prefix sum equal to given sum ( prefix-k==0)
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		int val = sum - k;
		if(hash[val]!=0)// previously occured
		{
			count+=1;
			hash.clear();
			sum = 0;
			hash[0]=1;// prefix sum equal to given sum ( prefix-k==0)
			continue;
		}
		hash[sum]+=1;
	}
	return count;
}


// negative integers also given
// subarrays can overlap
int main()
{
	int n,k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve3(arr,n,k) << endl;
}