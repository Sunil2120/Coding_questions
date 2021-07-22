#include<bits/stdc++.h>
using namespace std;


int find_touches(int pos,int mask,vector<string> v,int** dp)
{
	if(!(mask&(mask-1))&&mask) 
	// everything was recongnised successfully when mask contains only one bit set 
		return 0; 

	if(pos == -1||mask == 0) 
		return 100000;
    
	if(dp[pos][mask]!=INT_MAX)
	{
		return dp[pos][mask];
	}

	int newmask_zero =0;
	int newmask_one = 0;
	int touches = 0;
	for(int i=0;i<v.size();i++)//n
	{
		if((mask&(1<<i))!=0)
		{
			touches++;
			if(v[i][pos]=='0')
			{
				newmask_zero = newmask_zero|(1<<i);
			}
			else
			{
				newmask_one = newmask_one|(1<<i);
			}
		}
	}
	int ans1 = find_touches(pos-1,newmask_zero,v,dp)+find_touches(pos-1,newmask_one,v,dp) + touches;
	int ans2 = find_touches(pos-1,mask,v,dp);// ignoring the current character or current position
	int ans = min(ans1,ans2);
	dp[pos][mask]=ans;
	return ans;
}

int minimumTouchesRequired(int n,vector<string> v)//position x mask
{
	int** dp = new int*[v[0].size()];
	for(int i=0;i<v[0].size();i++)
	{
		dp[i]=new int[(1<<n+1)];
		for(int j=0;j<(1<<(n+1));j++)
		{
			dp[i][j]=INT_MAX;
		}
	}
	int ans =  find_touches(v[0].size()-1,(1<<n)-1,v,dp);
	for(int i=0;i<v[0].size();i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<string> input;
	for(int i=0;i<n;i++)
	{
		string x;
		cin >> x;
		input.push_back(x);
	}
	cout << minimumTouchRequired(n,input) << "\n";
	return 0;
}