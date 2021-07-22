#include<bits/stdc++.h>
using namespace std;

int solve2(int** gold,int m,int n,int sx,int sy)
{
	if(sy==n-1)// last column no where to go..
	{
		return gold[sx][sy];
	}
	int first = 0;
	int second = 0;
	int third = 0;
	if(sx-1 >=0)
	{
		first = solve2(gold,m,n,sx-1,sy+1);
	}
	second = solve2(gold,m,n,sx,sy+1);
	if(sx+1 < m)
	{
		third = solve2(gold,m,n,sx+1,sy+1);
	}
	return max(first,max(second,third))+gold[sx][sy];

}

// iterative
int solve3(int** gold,int m,int n)
{

	int** dp = new int*[m];
	for(int i=0;i<m;i++)
	{
		dp[i]=new int[n]();
	}
	for(int i=0;i<m;i++)
	{
		dp[i][n-1]=gold[i][n-1];
	}

	for(int j=n-2;j>=0;j--)
	{
		for(int i=0;i<m;i++)
		{
			int first = 0;
			int second = 0;
			int third = 0;
			if(i-1 >=0 )
			{
				first = dp[i-1][j+1];
			}
			second = dp[i][j+1];
			if(i+1 < m)
			{
				third = dp[i+1][j+1];
			}
			dp[i][j]=max(first,max(second,third))+gold[i][j];
		}
	}
	int max_value = INT_MIN;
	for(int i=0;i<m;i++)
	{
		cout << dp[i][0] << " ";
		max_value = max(max_value,dp[i][0]);
	}
	cout << endl;
	for(int i=0;i<m;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return max_value;


}

int solve(int** gold,int m,int n)
{
	int max_ = INT_MIN;
	for(int i=0;i<m;i++)
	{
		int temp = solve2(gold,m,n,i,0);
		max_ = max(max_,temp);
	}
	return max_;

}

int main()
{
	int m,n;
	cin >> m >> n;
	int** gold = new int*[m];// rows
	for(int i=0;i<m;i++)
	{
		gold[i]=new int[n];// col
		for(int j=0;j<n;j++)
		{
			cin >> gold[i][j];
		}
	}
	cout << solve(gold,m,n) << endl;
	cout << solve3(gold,m,n) << endl;

}