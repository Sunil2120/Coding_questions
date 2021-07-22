#include<bits/stdc++.h>
using namespace std;

long long solve(int n,int m,int l)
{
	if(n==0 || m==0 || l==0)
	{
		return 0;
	}
	long long row = 0;
	if(n < l)
	{
		row = 1;
	}
	else
	{
		row = n/l;
		if(n%l > 0)
		{
			row+=1;
		}
	}
	//col
	long long col = 0;
	if(m < l)
	{
		col = 1;
	}
	else
	{
		col = m/l;
		if(m%l > 0)
		{
			col+=1;
		}
	}
	return row*col;
}


int main()
{
	int n,m,l;
	cin >> n >> m  >> l;
	cout << solve(n,m,l) << endl;
	return 0;
}