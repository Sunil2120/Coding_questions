#include<bits/stdc++.h>
using namespace std;

// we can get ncr in o(N) time
// ncr = ncn-r  if(r > n-r)
// catalan number Cn = 2nCn/(n+1)




int nCr(int n,int r)
{
	int total = 1;
	if(r > (n-r))
	{
		r = n-r;
	}
	for(int i=0;i<r;i++)
	{
		total=total*(n-i);
		total=total/(i+1);
	}
	return total;
}

int solve(int n)
{
	int value = nCr(2*n,n);
	return value/(n+1);
}

int gcd(int a,int b)
{
	if(b > a)
	{
		return gcd(b,a);
	}
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main()
{
	int t;
	while(t--)
	{
		int n;
		cin >> n;
		int count = 0;
		for(int i=1;i<n;i++)
		{
			if(gcd(n,i)==1)
			{
				count+=1;
			}
		}
		cout << count << " " << solve(count/2) << endl;
	}
	

	return 0;
}