// Maximum subsequence sum such that no three are consecutive
// Last Updated: 25-04-2019
// Given a sequence of positive numbers, 
// find the maximum sum that can be formed which has no three consecutive elements present.


//   solution
// sum[i] : Stores result for subarray arr[0..i], i.e.,
//          maximum possible sum in subarray arr[0..i]
//          such that no three elements are consecutive.

// sum[0] = arr[0]

// // Note : All elements are positive
// sum[1] = arr[0] + arr[1]

// // We have three cases
// // 1) Exclude arr[2], i.e., sum[2] = sum[1]
// // 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// // 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] 
// sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

// In general,
// // We have three cases
// // 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
// sum[i] = max(sum[i-1], sum[i-2] + arr[i],
//              sum[i-3] + arr[i] + arr[i-1])
#include<bits/stdc++.h>
using namespace std;


// o(n) time and o(n) auxillary space
int solve(vector<int>& arr,int n)
{
	vector<int> dp;
	if(n == 0)
	{
		return 0;
	}
	if(n==1)
	{
		return arr[0];
	}
	if(n==2)
	{
		return arr[0]+arr[1];
	}
	if(n==3)
	{
		return max(arr[0]+arr[1],max(arr[1]+arr[2],arr[0]+arr[2]));
	}
	dp.assign(n,0);
	dp[0]=arr[0];
	dp[1]=arr[0]+arr[1];
	dp[2]=max(dp[1],max(dp[0]+arr[2],arr[1]+arr[2]));
	for(int i=3;i<n;i++)
	{
		// to avoid three consecutive elements we will exclude the 3rd element
		int option1 = dp[i-1];
		// to avoid three consecutive elements we will exclude the 2nd element
		int option2 = dp[i-2]+arr[i];
		// to avoid three consecutive elements we will exclude the 1st element
		int option3 = dp[i-3]+arr[i-1]+arr[i];
		dp[i]=max(option1,max(option2,option3));// we will get the max of 3
	}
	return dp[n-1];
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n) << endl;
	return 0;
}