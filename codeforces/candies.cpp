#include<bits/stdc++.h>
using namespace std;


bool solveHelper(vector<int>& arr,int index,int cur_sum,int sum,int k)
{
	if(index > arr.size())
	{
		return false;
	}

	if(cur_sum==sum )
	{
		return true;
	}
	if(cur_sum > sum)
	{
		return false;
	}
	bool first = solveHelper(arr,index+1,cur_sum+arr[index],sum,k);
	bool second = solveHelper(arr,index+1,cur_sum,sum,k);
	return first || second;
}

bool solve2(vector<int>& arr,int sum)
{
	bool** dp = new bool*[arr.size()+1];
	for(int i=0;i<=arr.size();i++)
	{
		dp[i]=new bool[sum+1]();
	}
	for(int i=0;i<=arr.size();i++)
	{
		dp[i][0]=true;
	}
	
	for(int i=1;i<=arr.size();i++)
	{
		for(int j=1;j<=sum;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j-arr[i-1] >=0)
			{
				dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	return dp[arr.size()][sum];



}

bool solve(vector<int>& arr,int n)
{
	if(n==0)
	{
		return true;
	}
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if(sum&1)
	{
		return false;
	}
	sum = sum/2;
	int k = n/2;
	return solve2(arr,sum);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		if(solve(arr,n))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}