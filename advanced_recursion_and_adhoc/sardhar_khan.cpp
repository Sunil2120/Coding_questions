#include<bits/stdc++.h>
using namespace std;

int main()
{
	double a,b;
	cin >> a >> b;
	if(a==0)
	{
		cout << fixed << setprecision(6) << 1.0 << endl;
		return 0;
	}
	if(b==0)
	{
		cout << fixed << setprecision(6) << 0.0 << endl;
		return 0;
	}
	if( a > b)
	{
		cout << fixed << setprecision(6) << 0.0  << endl;
		return 0;
	}

	// probability that a is never ahead of b
	// ans = (b +1 - a)/(b+1)  b >= a
	double ans = b + 1 - a;
	double d = b+1;
	ans = ans / d;
	cout << fixed << setprecision(6) << ans << endl;
	

}