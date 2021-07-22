#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ispossible(ll cur,vector<int>& pages,int n,int m)
{
	int students = 1;
	int cur_pages = 0;
	for(int i=0;i<n;i++)
	{
		if(pages[i] > cur)// we can't assign this book to anyone so false
		{
			return false;
		}
		if(pages[i]+cur_pages > cur)
		{
			students+=1;
			cur_pages = pages[i];
			if(students > m)
			{
				return false;
			}
		}
		else
		{
			cur_pages+=pages[i];
		}
	}
	return true;
}

ll solve(vector<int>& pages,int n,int m)
{
	ll low = 0;
	ll high = 0;
	for(int i=0;i<n;i++)
	{
		high+=pages[i];
	}
	ll result = INT_MAX;
	while(low<=high)
	{
		ll mid = low + (high-low)/2;
		if(ispossible(mid,pages,n,m)==true)
		{
			result = min(result,mid);
			// we need minimum pages as possible 
			high = mid-1;//left
		}
		else
		{
			low = mid+1;
		}
	}
	return result;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> pages(n);
	for(int i=0;i<n;i++)
	{
		cin >> pages[i];
	}
	cout << solve(pages,n,m) << endl;
	return 0;
}