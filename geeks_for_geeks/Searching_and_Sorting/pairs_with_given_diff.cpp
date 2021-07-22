#include<bits/stdc++.h>
using namespace std;

// time O(n) and space O(n)
int solve(vector<int>& arr,int n,int k)
{
	if(n==0 || n==1)
	{
		return 0;
	}
	int count = 0;
	unordered_map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		hash[arr[i]]+=1;
	}
	unordered_map<int,int> :: iterator it;
	for(auto it=hash.begin();it!=hash.end();it++)
	{
		if(k==0)
		{
			if(hash[it->first] > 1)
			{
				count+=1;
			}
			continue;
		}
		int req = k + it->first;
		if(hash.find(req)!=hash.end())
		{
			count+=1;
		}
	}
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