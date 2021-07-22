#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
typedef long long ll;

void getprimes(vector<int>& pri)
{
	bool* primes = new bool[MAX+1];
	for(int i=0;i<=MAX;i++)
	{
		primes[i]=true;
	}
	primes[0]=false;
	primes[1]=false;
	for(int i=2;i*i<=MAX;i++)
	{
		if(primes[i]==true) // is  a prime
		{
			// make all its multiple false
			for(int j=i*i;j<=MAX;j+=i)
			{
				primes[j]=false;
			}
		}
	}
	for(int i=2;i<=MAX;i++)
	{
		if(primes[i]==true)
		{
			pri.push_back(i);
		}
	}
	return ;
}

ll solve(ll l,ll r,int k,vector<int>& pri)
{
	ll* output = new ll[r-l+1];
	for(int i=0;i<=(r-l);i++)
	{
		output[i]=i+l;
	}

	for(int i=0;pri[i]<=r;i++)
	{
		int cur_p = pri[i];
		ll base = (l/cur_p)*cur_p;
		if(base < l)
		{
			base = base + cur_p;
		}
		for(ll i=base;i<=r;i+=cur_p)
		{
			output[i-l] = (output[i-l]*(cur_p-1))/cur_p;
		}
		if(base==cur_p)
		{
			output[base-l]= base;
		}
	}
	for(int i=0;i<=(r-l);i++)
	{
		if(output[i]==(i+l))
		{
			output[i]=i+l-1;
		}
	}
	int count = 0;
	for(int i=0;i<=(r-l);i++)
	{
		if(output[i]==0)
		{
			continue;
		}
		if((output[i]%k)==0)
		{
			count++;
		}
	}
	return count;

}

int main()
{
	int t;
	cin >> t;
	vector<int> pri;
	getprimes(pri);
	while(t--)
	{
		ll l,r;
		int k;
		cin >> l >> r >> k;
		double d = (r-l+1);
		double ans = solve(l,r,k,pri)/d;
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}