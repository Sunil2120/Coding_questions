#include<bits/stdc++.h>
using namespace std;


// time O(log(max_dist-min_dist)*n)
// space O(1)
typedef long long ll;
bool isPossible(vector<ll>& stalls,ll dist,ll n,ll c)
{
	ll first = 0;
	c-=1;
	for(ll i=1;i<n;i++)
	{
		if(stalls[i]-stalls[first] >= dist)
		{
			first = i;
			c-=1;
			if(c==0)
			{
				return true;
			}
		}
	}
	return false;
}

ll solve(vector<ll>& stalls,ll n,ll c)
{
	if(c > n)
	{
		return -1;
	}
	if(n==0)
	{
		return -1;
	}
	sort(stalls.begin(),stalls.end());
	ll low = 1;
	ll high = stalls[n-1]-stalls[0];
	ll  ans = 0;
	while(low<=high)
	{
		ll mid = low + (high-low)/2;
		if(isPossible(stalls,mid,n,c))
		{
			ans=mid;
			// maximize the min distance
			low = mid+1;
		}
		else
		{
			// if it is not possible for mid it is not possible for all mid+1
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
		ll n,c;
		cin >> n >> c;
		vector<ll> stalls(n);
		for(int i=0;i<n;i++)
		{
			cin >> stalls[i];
		}
		cout << solve(stalls,n,c) << endl;
	}
	return 0;
}