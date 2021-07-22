#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k)
{
	int comb[n+1] = { 0 };
	comb[0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j>=i)
			{
				comb[j]+=comb[j-i];
			}
		}
	}
	return comb[n];
}

int main()
{
	int n,k;
	cin >> n >> k;
	cout << solve(n,k) << endl;
	return 0;
}