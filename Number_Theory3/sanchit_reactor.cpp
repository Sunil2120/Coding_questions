// if (t/m) is odd => ans = ((m-1)*(t%m))%m
// if(t/m) is even => ans = (1*(t%m))%m
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve1(int a, int m){
	ll res=1;
	for(int i=2;i<=a;i++)
		res=(res%m * i%m)%m;
	return res;
}


ll solve(ll t,int m)
{
	if(t>=m)
	{
		int value = t/m;
		ll ans = 1;
		ll suni = solve1((t%m),m); // this will give (t%m)! mod m
        suni = suni%m;
		// if(t/m is odd)
		if((value%2)!=0)
		{
			ans = ((ans*(m-1))%m*suni);
			ans = ans%m;
		}
		else // (t/m is even)
		{
			ans = ans*(suni);
			ans = ans%m;
		}
		return ans;
	}
	else
	{
        if((m-t)==1)
        {
            return 1;
        }
		ll fact = solve1((t%m),m);
        fact = fact%m;
		return fact;
	}

	return 0;
	
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll t;
		int m;
		cin >> t >> m;
		cout << solve(t,m) << endl;
	}
}