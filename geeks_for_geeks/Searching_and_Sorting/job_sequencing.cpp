#include<bits/stdc++.h>
using namespace std;


struct job
{
	int start;
	int end;
	int profit;
};

typedef struct job Job;

bool compare(Job a,Job b)
{
	if(a.end < b.end)
	{
		return true;
	}
	return false;
}

int findLatest(vector<Job>& arr,int index)
{
	int low = 0;
	int high = index-1;
	int ans=-1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid].end <= arr[index].start)
		{
			ans = mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return ans;
}
int solve(vector<Job>& arr,int n)
{

	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return arr[n-1].profit;
	}
	int latest = findLatest(arr,n-1);
	int output = 0;
	if(latest!=-1)
	{
		output=max(output,solve(arr,latest+1)+arr[n-1].profit);
	}
	output = max(output,solve(arr,n-1));
	return output;

}

int solve2(vector<Job>& arr,int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return arr[n-1].profit;
	}
	int* dp = new int[n]();
	dp[0]=arr[0].profit;
	for(int i=1;i<n;i++)
	{
		int j = findLatest(arr,i);
		if(j!=-1)
		{
			dp[i]=dp[j]+arr[i].profit;
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	return dp[n-1];

}
int main()
{
	int n;
	cin >> n;
	vector<Job> arr(n);
	for(int i=0;i<n;i++)
	{
		Job temp;
		cin >> temp.start ;
		cin >> temp.end;
		cin >> temp.profit;
		arr[i]=temp;
	}
	sort(arr.begin(),arr.end(),compare);

	cout << solve(arr,n) << endl;
	cout << solve2(arr,n) << endl;
	return 0;
}