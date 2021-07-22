// using fermet's and wilson theorem
// refer notes for more details
#include<bits/stdc++.h>
using namespace std;
typedef long  ll;

ll power(int a,int b,int c)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	ll value = power(a,b/2,c);
	ll ans = value*value;
	ans = ans%c;
	if((b%2)!=0)// b is odd
	{
		ans = (ans*(a%c))%c;
	}
	return ans;

}


int mmi(int a,int m) //  m should be prime
{	

	return (power(a,m-2,m));


}

ll solve(int n,int p)
{
	// we should find (n!)%p
	ll ans = -1;
	for(int i=n+1;i<=(p-1);i++)
	{
		ans = ans*mmi(i,p);
		ans = ans%p;
	}
	return (ans+p);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,p;
		cin >> n >> p;
		if(n>=p)
		{
			cout << 0 << endl;
			continue;
		}
		cout << solve(n,p) << endl;
	}
	
	return 0;
}