#include<bits/stdc++.h>
using namespace std;



int mex(unordered_set<int>& s)
{
	int max = 0;
	while(s.find(max)!=s.end())//max is present
	{
		max+=1;
	}
	return max;
}

int G(int n,int k,vector<int>& dp)
{
	if(n==0)
	{
		dp[n]=0;
		return 0;
	}
	if(n<k)
	{
		dp[n]=0;
		return 0;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	unordered_set<int> s;
	s.insert(G(n-k,k,dp));
	dp[n]=mex(s);
	return dp[n];

}


void solve(vector<int>& piles,int n)
{
	if(n==1)
	{
		cout << "A" << endl;
		return ;
	}
	vector<int> dp(1001,-1);
	int XOR = G(piles[0],1,dp);
	for(int i=1;i<n;i++)
	{
		XOR = XOR^(G(piles[i],i+1,dp));
	}
	if(XOR > 0)
	{
		cout << "A" << endl;
	}
	else
	{
		cout << "B" << endl;
	}
	
	return ;

}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> piles(n);
		for(int i=0;i<n;i++)
		{
			cin >> piles[i];
		}
		solve(piles,n);
	}
	return 0;
}