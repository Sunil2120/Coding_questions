#include <bits/stdc++.h>
using namespace std;


/*Let dp[i] be optimal cost to rach (i,0) then we have 2 cases:

if i is even: then we can either reach it from i-1 or from i/2 (Note that going a step back from i+1 wont lead to optimal cost as reaching i+1 involves reaching i/2 or i first)

dp[i]= minimum(dp[i/2]+B,dp[i-1]+A)

if i is odd: then we can either reach it by making a  jump from i/2 and then moving a step forward, or making a jump from (i+1)/2 and then moving a step back or just moving a step forward from i-1

dp[i]=minimum(dp[i/2]+A+B,dp[(i+1)/2]+A+B,dp[i-1]+A)*/


int solve(int x,int y,int n,int A,int B)
{
   int* dp = new int[n+1]();
   dp[0]=0;
   for(int i=1;i<=n;i++)
   {
        if(i%2 == 0)//even
        {
            dp[i]=min(dp[i/2]+B,dp[i-1]+A);
        }
        else
        {
            //odd
            dp[i]=min(dp[i/2]+B+A,min(dp[(i+1)/2]+B+A,dp[i-1]+A));
        }
   }
   return dp[n];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,A,B;
	    cin >> n >> A >> B;
	    cout << solve(0,0,n,A,B) << endl;
	}
	return 0;
}