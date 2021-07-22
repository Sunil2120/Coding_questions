#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> arr)
{
	int* output = new int[1000+1]();
	int* freq = new int[1000+1]();
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]+=1;
	}
	output[0]=0;
	output[1] = 1*freq[1];
	for(int i=2;i<=1000;i++)
	{
		// we will include the current element
		int cur = i*freq[i] + output[i-2]; // we can't consider the prev element if we include the cur element
		// we wont include the current element consider the previous  element;
		int prev = output[i-1];
		output[i] = max(cur,prev);
	}
	int ans = output[1000];
	delete[] output;
	delete[] freq;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}
	cout << solve(n,arr);
	return 0;
}