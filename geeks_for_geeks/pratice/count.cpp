#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr,int n,int sum)
{
	int* dp=new int[n]();
	dp[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+arr[i];
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(dp[i]==0)
		{
			count+=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int temp=dp[j]-dp[i-1];
			if(temp==0)
			{
				count+=1;
			}
		}
	}
	
	return count;
}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
	int m=matrix.size();
	int n=matrix[0].size();
	int res=0;
	for(int i=0;i<n;i++)
	{
		vector<int> temp(m,0);
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				temp[k]+= matrix[k][j];
			}
			res+= solve(temp,m);

		}
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,0) << endl;
	return 0;
}