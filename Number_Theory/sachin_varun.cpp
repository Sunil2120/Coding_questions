// give a,b and d
// we should used some units of a and some units of b to make d units
// ax + by = d
// we should find different pairs of x and y
// pairs of x and y = n+1
// time complexity is to find mmi -> o(log(max(a,b)))
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


struct triplet
{
	ll x;
	ll y;
	ll gcd;

};
typedef struct triplet triplet;


triplet* solve(ll a,ll b)
{
	// base case
	if(b==0)
	{
		triplet* temp = new triplet();
		temp->x = 1;
		temp->y = 0;
		temp->gcd = a;
		return temp;
	}
	triplet* smallans = solve(b,a%b);
	triplet* ans = new triplet();
	ans->x = smallans->y;
	ans->y = smallans->x - (a/b)*smallans->y;
	ans->gcd = smallans->gcd;
	return ans;
}


ll mmI(ll a,ll m)
{
	ll x = solve(a,m)->x;
	// x can be negative
	return (x%m + m)%m;
}

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll a,b,d;
		cin >> a >> b >> d;
		ll g = __gcd(a,b);// inbuilt gcd function
		// to get integral solutions of  x and y gcd(a,b) should divide d
		if(d==0)
		{
			cout << 1 << endl;
			continue;
		}
		if(d%g !=0)// not divisible
		{
			cout << 0 << endl;
			continue;
		}
		// we are further optimizing
		a=a/g;
		b=b/g;
		d=d/g;
		// n = (d/b - y1)/a;
		// y1 = (d%a *mmI(b,a))%a;
		ll first = d/b;
		ll y1 = ((d%a)*mmI(b,a))%a;
		if(d < (y1*b))// n will become negative
		{
			cout << 0 << "\n";
			continue;
		}
		ll n = (first - y1)/a;
		cout << n+1 << endl; // n+1 is the ans
	}
	return 0;
}