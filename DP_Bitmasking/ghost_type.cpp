#include<bits/stdc++.h>
using namespace std;


int solve(int n,int mask)
{
	if(mask==((1<<n)-1))
	{
		return 1;
	}
	int count = 0;
	
	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			int check = 0;
			for(int j=0;j<n;j++)
			{
				if((mask&(1<<j))!=0)// bit is set checking
				{
					int suni = (i+1)&(j+1);
					if(suni==i+1)
					{
						check = 1;// we are not supposed to put
					}
				}
			}
			if(check==1)
			{
				continue;
			}
			else
			{
				count+=solve(n,mask|(1<<i));
			}
		}
	}
	return count;
}

int solve2(int n,int mask,int* dp)
{
	if(mask==((1<<n)-1))
	{
		return 1;
	}
	if(dp[mask]!=0)
	{
		return dp[mask];
	}
	int count = 0;
	
	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			int check = 0;
			for(int j=0;j<n;j++)
			{
				if((mask&(1<<j))!=0)// bit is set checking
				{
					int suni = (i+1)&(j+1);
					if(suni==i+1)
					{
						check = 1;// we are not supposed to put
						break;
					}
				}
			}
			if(check==1)
			{
				continue;
			}
			else
			{
				count+=solve2(n,mask|(1<<i),dp);
			}
		}
	}
	dp[mask]=count;
	return count;
}


int main()
{
	int n;
	cin >> n;
	int* dp = new int[(1<<n)]();
	cout << solve(n,0) << endl;
	cout << solve2(n,0,dp) << endl;
	return 0;
}