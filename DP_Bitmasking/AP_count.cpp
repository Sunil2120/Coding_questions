#include<bits/stdc++.h>
using namespace std;
#define mod 100001;
typedef long long ll;


ll solve(int* arr,int n)
{
	unordered_map<int,int>* hash = new unordered_map<int,int>[n];// each index stores the diff information
	ll count = n+1;// all single elements + empty set
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int diff = arr[j]-arr[i];
			hash[i][diff]+=1;
			count+=1;
			count=count%mod;
		}
	}

	// now we are starting from end 
	for(int i=n-3;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			int diff= arr[j]-arr[i];
			count+=hash[j][diff];
			count=count%mod;
			hash[i][diff]=hash[i][diff]+hash[j][diff];
		}
	}
	return count;
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n) << endl;
	return 0;
}