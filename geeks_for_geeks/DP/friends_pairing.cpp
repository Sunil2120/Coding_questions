// if cur person remaining single f(n-1)
// if cur person pairs with remaining n-1 persons (n-1)*f(n-2) // f(n-2) because paired person should not undergo pairing again
// total ways = f(n-1) + (n-1)*f(n-2)

#include<bits/stdc++.h>
using namespace std;
// recursion
int solve(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	if(n<=2)
	{
		return n;
	}
	return solve(n-1)+(n-1)*solve(n-2);
}

// iterative
int solve1(int n)
{
	int* dp = new int[n+1]();
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++)
	{
		dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	int ans = dp[n];
	delete[] dp;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	cout << solve1(n)<< endl;
	return 0;
}