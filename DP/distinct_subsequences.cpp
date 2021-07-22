#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(string input,int n)
{
	long long* dp = new long long[n+1];
	int* last = new int[26];
	for(int i=0;i<26;i++)
	{
		last[i]=-1;
	}
	dp[0]=1;//empty string
	for(int i=1;i<=n;i++)
	{
		dp[i]=2*dp[i-1];
		dp[i]=dp[i]%MOD;
		if(last[input[i-1] - 'A'] > -1)
		{
			int index = last[input[i-1] - 'A'];
			dp[i]=dp[i] - dp[index - 1]; // this value can be negative
            dp[i]=((dp[i])%MOD + MOD)%MOD; 
		}
		last[input[i-1] - 'A']=i;
	}
	int ans =  dp[n];
	delete[] dp;
	delete[] last;
	return ans;
}


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string input;
        cin >> input;
        cout << solve(input,input.size()) << endl;
    }
	
	return 0;
}