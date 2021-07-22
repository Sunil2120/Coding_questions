#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isPossible(vector<ll>& arr,ll n,ll k,ll cut)
{
	long long total=0;
	for(ll i=0;i<n;i++)
	{
		if(arr[i] > cut)
		{
			total+=(arr[i]-cut);
		}
	}
	if(total >= k)
	{
		return true;
	}
	return false;
}

ll solve(vector<ll>& arr,ll n,ll k)
{
	if(n==0)
	{
		return 0;
	}
	ll max_value = arr[0];
	for(ll i=1;i<n;i++)
	{
		max_value = max(max_value,arr[i]);
	}
	ll ans=-1;
	ll low=0;
	ll high = max_value;
	while(low<=high)
	{
		ll mid = (low + high)/2;
		if(isPossible(arr,n,k,mid))
		{
			ans = mid;
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
	ll n,k;
	cin >> n >> k;
	vector<ll> arr(n);
	for(ll i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
	return 0;
}