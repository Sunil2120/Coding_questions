// finding min cost to assign n jobs to n persons
#include<bits/stdc++.h>
using namespace std;

int min_cost(int** arr,int n,int cur_p,int mask)
{
	if(cur_p>=n)
	{
		return 0;
	}
	int min_x = INT_MAX;

	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)// bit is not set
		{
			int value  = min_cost(arr,n,cur_p+1,mask|(1<<i))+arr[cur_p][i];
			if(value < min_x)
			{
				min_x = value;
			}
		}
	}
	return min_x;
}


int min_cost2(int** arr,int n,int cur_p,int mask,int* dp)
{
	if(cur_p >=n)
	{
		return 0;
	}
	if(dp[mask]!=-1)
	{
		return dp[mask];
	}
	int min_x = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)// bit is not set
		{
			int value  = min_cost2(arr,n,cur_p+1,mask|(1<<i),dp)+arr[cur_p][i];
			if(value < min_x)
			{
				min_x = value;
			}
		}
	}
	dp[mask]=min_x;// result will be storedin dp[0];
	return min_x;
}

//iterative solution

int min_cost3(int** arr,int n)
{
	int* dp = new int[1<<n];
	for(int i=0;i<(1<<n);i++)
	{
		dp[i]=INT_MAX;
	}
	dp[0]=0;

	for(int mask=0;mask<(1<<n)-1;mask++)
	{
		int k=0;
		int temp = mask;
		// to count number of set bits
		while(temp>0)
		{
			if(temp%2==1)
			{
				k++;
			}
			temp=temp/2;
		}
		for(int i=0;i<n;i++)
		{
			if((mask&(1<<i))==0)// bit is not set
			{
				dp[mask|(1<<i)]=min(dp[mask|(1<<i)],dp[mask]+arr[k][i]);
			}
		}
	}
	int ans =  dp[(1<<n)-1];
	delete[] dp;
	return ans;
}


int main()
{
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n]();
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	int* dp = new int[(1<<n)];
	for(int i=0;i<(1<<n);i++)
	{
		dp[i]=-1;
	}
	cout << min_cost(arr,n,0,0) << endl;
	cout << min_cost2(arr,n,0,0,dp) << endl;
	cout << min_cost3(arr,n) << endl;

}
