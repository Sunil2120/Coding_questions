#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr,int n)
{
	int max_element = INT_MIN;
	unordered_map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		max_element = max(max_element,arr[i]);
		hash[arr[i]]+=1;
	}
	cout << max_element << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=2;j*arr[i]<=max_element;j++)
		{
			if(hash[j*arr[i]] > 0)
			{
				hash[j*arr[i]]+=1;
			}
		}
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(hash[arr[i]] > 1)
		{
			count+=1;
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