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
int main()
{
	int n;
	cin >> n;
	cout << solve(n/2) << endl;
	return 0;
}