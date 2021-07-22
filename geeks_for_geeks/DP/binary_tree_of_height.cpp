//Count Balanced Binary Trees of Height h
// balanced binary trees are those trees whose diff b/w left and right tree is not more than 1
// if h==0 or h==1 return 1
// ans = count(h-1,h-1)+count(h-1,h-2)+count(h-2,h-1)
#include<bits/stdc++.h>
using namespace std;

int solve(int h)
{
	int* dp = new int[h+1]();
	dp[0]=1;// no nodes 1 way
	dp[1]=1;// 1 node means 1 way
	for(int i=2;i<=h;i++)
	{
		dp[i]=(dp[i-1]*dp[i-1])+(dp[i-1]*dp[i-2])+(dp[i-2]*dp[i-1]);
	}
	return dp[h];

}

int main()
{
	int h;
	cin >> h;
	cout << solve(h) << endl;
}