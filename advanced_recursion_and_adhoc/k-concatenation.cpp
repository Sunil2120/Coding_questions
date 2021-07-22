#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane(int* arr,int n)
{
	ll cur = 0;
	ll max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		cur = cur + arr[i];
		if(cur > max)
		{
			max = cur;
		}
		if(cur< 0)
		{
			cur = 0;
		}
	}
	return max;
}

ll k_concat(int* arr,int n,int k)
{
	if(k==1)
	{
		return kadane(arr,n);
	}
	ll max_pref=INT_MIN;
	ll max_suf=INT_MIN;
	ll cur_pref=0;
	ll cur_suf=0;
	// to find maximum suffix sum
	for(int i=0;i<n;i++)
	{
		cur_suf+=arr[i];
		max_suf = max(cur_suf,max_suf);
	}
	ll total= cur_suf;// sum of all elements
	// to find maximum prefix sum
	for(int i=n-1;i>=0;i--)
	{
		cur_pref+=arr[i];
		max_pref = max(cur_pref,max_pref);
	}
	if(total > 0)
	{
		return (max(max_suf+max_pref+(k-2)*total,kadane(arr,n)));
	}
	else
	{
		return (max(max_suf+max_pref,kadane(arr,n)));
	}

}



int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int size;
		cin >> size;
		int k;
		cin >> k;
		int* arr = new int[size];
		for(int i=0;i<size;i++)
		{
			cin >> arr[i];
		}
		cout << k_concat(arr,size,k)<< endl;
		delete [] arr;
	}
	return 0;
}