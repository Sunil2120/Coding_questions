// given n and k we have return no of ways in which out of n days k days he can be happy
// he will be happy while playing and sleeping
// refer notes
// ans = nck * 2^k
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void fact(ll* arr)
{
	ll result = 1;
	for(int i=1;i<=1000000;i++)
	{
		result = (result%MOD)*(i%MOD);
		result = result%MOD;
		arr[i]=result;
	}
	return;
}

int power(ll a,int b)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	ll value = power(a,b/2);
	ll ans = (value*value)%MOD;
	if((b%2)!=0)
	{
		ans = (ans*(a%MOD))%MOD;
	}
	return ans;
}

int mmi(ll a)
{
	return power(a,MOD-2);
}

int solve(int n,int k,ll* arr)
{
	ll suni = power(2,k);
	ll result = 1;
	ll fvalue = arr[n];
	ll svalue1 = arr[n-k];
	ll tvalue1 = arr[k];
	ll s = mmi(svalue1);
	ll t = mmi(tvalue1);
	result = (((result *(fvalue))%MOD*s)%MOD*t)%MOD;
	result = (result*suni)%MOD;
	return result;
}

int main()
{
	int t;
	cin >> t;
	ll* arr = new ll[1000001]();
	fact(arr);
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		cout << solve(n,k,arr) << endl;
	}
	delete[] arr;
	return 0;
}