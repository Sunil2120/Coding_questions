#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000001;
typedef long long ll;


int solve(string a,string b,string c)
{
	// base case
	int a_l = a.length();
	int b_l = b.length();
	int c_l = c.length();
	if(c_l==0)
	{
		return 1;
	}
	if(b_l==0 && a_l==0 )
	{
		return 0;
	}
	int count = 0;
	for(int i=a_l-1;i>=0;i--)// finding last character of c in a
	{
		if(a[i]==c[c_l-1])
		{
			count+=solve(a.substr(0,i),b,c.substr(0,c_l-1));
		}
	}
	for(int i=b_l-1;i>=0;i--)// finding last character of c in a
	{
		if(b[i]==c[c_l-1])
		{
			count+=solve(a,b.substr(0,i),c.substr(0,c_l-1));
		}
	}
	return count;
}

ll solve2(string a,string b,string c,ll*** dp)
{
	// base case
	int a_l = a.length();
	int b_l = b.length();
	int c_l = c.length();
	if(c_l==0)
	{
		return 1;
	}
	if(b_l==0 && a_l==0 )
	{
		return 0;
	}
	if(dp[a_l][b_l][c_l]!=0)
	{
		return dp[a_l][b_l][c_l];
	}
	ll count = 0;
	for(int i=a_l-1;i>=0;i--)// finding last character of c in a
	{
		if(a[i]==c[c_l-1])
		{
			count+=solve2(a.substr(0,i),b,c.substr(0,c_l-1),dp);
			count=count%MOD;
		}
	}
	for(int i=b_l-1;i>=0;i--)// finding last character of c in a
	{
		if(b[i]==c[c_l-1])
		{
			count+=solve2(a,b.substr(0,i),c.substr(0,c_l-1),dp);
			count=count%MOD;
		}
	}
	dp[a_l][b_l][c_l]= count;
	return count;
}
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
typedef long long ll;



ll solve2(string a,string b,string c,ll*** dp)
{
	// base case
    int a_l = a.length();
	int b_l = b.length();
	int c_l = c.length();
    if(dp[a_l][b_l][c_l]!=0)
	{
		return dp[a_l][b_l][c_l];
	}

	if(c_l<=0)
	{
		return 1;
	}
	if(b_l<=0 && a_l<=0 )
	{
		return 0;
	}
	ll count = 0;
	for(int i=a_l-1;i>=0;i--)// finding last character of c in a
	{
		if(a[i]==c[c_l-1])
		{
			count+=solve2(a.substr(0,i),b,c.substr(0,c_l-1),dp);
            count=count%MOD;
		}
	}
	for(int i=b_l-1;i>=0;i--)// finding last character of c in a
	{
		if(b[i]==c[c_l-1])
		{
			count+=solve2(a,b.substr(0,i),c.substr(0,c_l-1),dp);
            count=count%MOD;

		}
	}
	dp[a_l][b_l][c_l]= count;
	return count;
}



int solve(string A,string B,string C)
{
	ll*** dp = new ll**[A.size()+1];
	for(int i=0;i<=A.size();i++)
	{
		dp[i]=new ll*[B.size()+1];
		for(int j=0;j<=B.size();j++)
		{
			dp[i][j]=new ll[C.size()+1]();
			// for(int k=0;k<=C.size();k++)
			// {
			// 	dp[i][j][k]=0;
			// }
		}
	}
    int ans = solve2(A,B,C,dp);
    for(int i=0;i<=A.size();i++)
	{
		for(int j=0;j<=B.size();j++)
		{
			delete[] dp[i][j];
		}
		delete[] dp[i];
	}
	delete[] dp;
    return ans;
    
}

int main()
{
	string A,B,C;
	cin >> A >> B >> C;
	cout << solve(A,B,C) << endl;
	ll*** dp = new ll**[A.size()+1];
	for(int i=0;i<=A.size();i++)
	{
		dp[i]=new ll*[B.size()+1];
		for(int j=0;j<=B.size();j++)
		{
			dp[i][j]=new ll[C.size()+1];
			for(int k=0;k<=C.size();k++)
			{
				dp[i][j][k]=0;
			}
		}
	}
	cout << solve2(A,B,C,dp) << endl;
	for(int i=0;i<=A.size();i++)
	{
		for(int j=0;j<=B.size();j++)
		{
			delete[] dp[i][j];
		}
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}