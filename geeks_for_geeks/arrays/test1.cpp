#include <bits/stdc++.h>
using namespace std;

int solve3(int l,int* len,int* profit,int n)
{
	int* dp = new int[l+1];
	for(int i=0;i<=l;i++)
	{
		dp[i]=-1;
	}
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		dp[len[i]]=profit[i];
	}
	for(int i=1;i<=l;i++)
	{
		
			int max_ = 0;
			int cur = i;
			for(int j=0;j<n;j++)
			{
				if((len[j] <= cur) && (cur-len[j])>=0)
				{
					int temp = dp[cur-len[j]];
					temp+=profit[j];
					max_ = max(temp,max_);
				}
			}
			dp[i]=max_;
	}
	// for(int i=0;i<=l;i++)
	// {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	int ans = dp[l];
	delete[] dp;
	return ans;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
    {
        int l;
        cin >> l;
        int* len = new int[l];
        int* profit = new int[l];
        for(int i=0;i<l;i++)
        {
            cin >> profit[i];
            len[i]=i+1;
        }
        cout << solve3(l,len,profit,l) << endl;
        delete[] len;
        delete[] profit;
    }
	
	return 0;
}