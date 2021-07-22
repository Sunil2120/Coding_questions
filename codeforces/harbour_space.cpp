#include<bits/stdc++.h>
using namespace std;

int solve(int x,int y)
{
	int** dp = new int*[x+1];
	for(int i=0;i<=x;i++)
	{
		dp[i]=new int[y+1]();
	}

	
	
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x,y;
		cin >> x >> y;
		cout << solve(x,y,0,0,0,-1,-1) << endl;
	}
}