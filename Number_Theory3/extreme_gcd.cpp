#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll Euler_totientphi(int n)
{
	ll phi[n+1];
	for(int i=1;i<=n;i++)
	{
		phi[i]=i;
	}
	phi[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(phi[i]==i)// this is a prime number 
		{
			phi[i]=i-1;// co-primes of prime number is prime number -1 
			// multiple all its multiple by (i-1)*i 
			for(int j=2;j*i<=n;j++)
			{
				phi[j*i]=(phi[j*i]*(i-1))/i;
			}
		}
	}
	ll result = phi[n];
	return result;
}



ll getdivisors(int n)
{
	ll total = 0;
	for(int i=1;i<n;i++)
	{
		if((n%i)==0)
		{
			total+= i*Euler_totientphi(n/i);
		}
	}
	return total;
	
}

ll solve(int n)
{
	ll ans = 0;
	for(int i=2;i<=n;i++)
	{
		ans += getdivisors(i);
	}
	return ans;
}

ll solve2(int n)
{
	ll* arr = new ll[n+1]();
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j*i<=n;j++)
		{
			arr[j*i]+= i*Euler_totientphi(j);
		}
	}
	ll total = 0;
	for(int i=0;i<=n;i++)
	{
		total+=arr[i];
	}
	return total;
}

int main()
{
	int n;
	cin >> n;
	cout << solve2(n) << endl;
	return 0;
}