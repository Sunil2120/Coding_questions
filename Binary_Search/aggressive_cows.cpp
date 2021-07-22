#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<int>& stalls,int n,int cows,int dist)
{
	int position = 0;
	int count = 1;
	for(int i=1;i<n;i++)
	{
		long long diff = abs(stalls[i]-stalls[position]);
		if(diff >= dist)
		{
			count+=1;
			position = i;
		}
		if(count == cows)
		{
			return true;
		}
	}
	return false;
}

long long solve(vector<int>& stalls,int n,int cows)
{
	long long low = 0;
	sort(stalls.begin(),stalls.end());
	long long high = stalls[n-1]-stalls[0];
	long long ans = -1;
	while(low<=high)
	{
		long long mid = low + (high-low)/2;
		if(isvalid(stalls,n,cows,mid)==true)
		{
			// mid can be our ans
			ans = mid;
			// we should maximize the minimum distance
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int cows;
		cin >> cows;
		vector<int> stalls(n);
		for(int i=0;i<n;i++)
		{
			cin >> stalls[i];
		}
		
		cout << solve(stalls,n,cows) << endl;
	}
	return 0;
}