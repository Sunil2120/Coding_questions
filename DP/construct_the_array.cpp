#include<bits/stdc++.h>
#define M 1000000007 
using namespace std;




long solve(int n,int k,int x)
{
	long onecount = 1;
	long nononecount = 0;
	for(int i=1;i<n;i++)
	{
		long temp = onecount;
		onecount = ((nononecount)*(k-1))%M;
		nononecount = (temp + ((nononecount)*(k-2))%M)%M;
		
	}
	if(x == 1)
	{
		return onecount;
	}
	return nononecount;
}
int main()
{
	int n,k;
	cin >> n >> k;
	cout << solve(n,k,1) << endl;
	cout << solve(n,k,2) << endl;
	return 0;
}