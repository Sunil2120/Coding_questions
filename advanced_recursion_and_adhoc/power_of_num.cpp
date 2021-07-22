#include<bits/stdc++.h>
using namespace std;



int solve_(int x,int n)
{
	if(x==0)
	{
		return 0;
	}
	if(n==0)
	{
		return 1;
	}
	n--;
	return x*solve_(x,n);
}


int main()
{
	int n;
	int x;
	cin>> x >> n;
	cout << solve_(x,n) << endl;
	return 0;
}