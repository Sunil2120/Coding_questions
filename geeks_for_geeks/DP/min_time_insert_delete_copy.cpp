#include<bits/stdc++.h>
using namespace std;

// dp o(n) time and o(n) auxillary space
int solve1(int n,int I,int D,int C)
{
	vector<int> dp(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(i%2 == 0)
		{
			dp[i]=min(dp[i-1]+I,dp[i/2]+C);
		}
		else
		{
			dp[i]=min(dp[i-1]+I,min(dp[(i-1)/2]+C+I,dp[(i+1)/2]+C+D));
		}
	}
	return dp[n];
}


int solve(int n,int cur,int I,int D,int C,unordered_set<int>& s)
{

	if(n==0)
	{
		return 0;
	}
	if(cur==n)
	{
		return 0;
	}
	if(cur > n)
	{
		return INT_MAX;
	}
	// insert
	int option1 = INT_MAX;
	if(s.find(cur+1)==s.end())
	{
		s.insert(cur+1);
		option1 = solve(n,cur+1,I,D,C,s);
		s.erase(cur+1);
		if(option1!=INT_MAX)
		{
			option1+=I;
		}
	}
	// delete
	int option2 = INT_MAX;
	if( cur > 0 && s.find(cur-1)==s.end())
	{
		s.insert(cur-1);
		option2 = solve(n,cur-1,I,D,C,s);
		s.erase(cur-1);
		if(option2!=INT_MAX)
		{
			option2+=D;
		}
	}
	int option3 = INT_MAX;
	if(s.find(cur+cur)==s.end())
	{
		s.insert(cur+cur);
		option3 = solve(n,cur+cur,I,D,C,s);
		s.erase(cur+cur);
		if(option3!=INT_MAX)
		{
			option3+=C;
		}
	}
	
	return min(option1,min(option2,option3));

}

int main()
{
	int n,I,D,C;
	cin >> n >> I >> D >> C;
	unordered_set<int> s;
	cout << solve1(n,I,D,C) << endl;
}