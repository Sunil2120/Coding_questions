#include<bits/stdc++.h>
using namespace std;

// o(nlogn)
int solve(int* arr,int n,int k)
{
	// intital
	sort(arr,arr+n);
	int ans = arr[n-1]-arr[0];
	// corner case
	int small = arr[0]+k;
	int big = arr[n-1]-k;
	if(small > big)
	{
		// swap
		int temp = small;
		small = big;
		big = temp;
	}
	// we will take care of middle cases
	for(int i=1;i<n-1;i++)
	{
		int add = arr[i]+k;
		int sub = arr[i]-k;
		// even if sub becomes negative it doesnot matter because big-(-sub) => big+sub
		// we want the diff b/w largest and smallest tower
		if(sub >= small || add <= big)
		{
			continue;
		}
		if((big - sub) <= (add - small) )// greedy method
		{
			small = sub;
		}
		else
		{
			big = add;
		}
	}
	return min(ans,(big-small));
}

// o(n)
int solve2(int* arr,int n,int k)
{
	int s = INT_MAX;
	int b = INT_MIN;
	// intital
	for(int i=0;i<n;i++)
	{
		s = min(s,arr[i]);
		b = max(b,arr[i]);
	}
	int ans = b-s;
	// corner case
	int small = s+k;
	int big = b-k;
	if(small > big)
	{
		// swap
		int temp = small;
		small = big;
		big = temp;
	}
	// we will take care of middle cases
	for(int i=0;i<n;i++)
	{
		if(arr[i]==s || arr[i]==b)
		{
			continue;// already taken care
		}
		int add = arr[i]+k;
		int sub = arr[i]-k;
		// even if sub becomes negative it doesnot matter because big-(-sub) => big+sub
		// we want the diff b/w largest and smallest tower
		if(sub >= small || add <= big)
		{
			continue;
		}
		if((big - sub) <= (add - small) )// greedy method
		{
			small = sub;
		}
		else
		{
			big = add;
		}
	}
	return min(ans,(big-small));
}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n,k) << endl;
		delete[] arr;
	}
	return 0;
}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n,k) << endl;
		delete[] arr;
	}
	return 0;
}