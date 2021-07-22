#include<bits/stdc++.h>
using namespace std;

// use dp to reduce time


int solve2(int* arr,int* cost,int n)
{
	if(n<=0)
	{
		return 0;
	}
	// one day pass
	int temp1 = INT_MAX;
	int temp2 = INT_MAX;
	int temp3 = INT_MAX;
	temp1 = solve2(arr+1,cost,n-1)+cost[0];
	// 7-day pass
	int end = arr[0]+6;// including that day
	int count = 0;
	for(int i=0;i< n && arr[i]<=end ;i++)
	{
		count+=1;
	}
	cout << count << endl;
	temp2 = solve2(arr+count,cost,n-count)+cost[1];
	// 30-day pass
	end = arr[0]+29;// including that day
	count = 0;
	for(int i=0;i< n && arr[i]<=end ;i++)
	{
		count+=1;
	}
	cout << count << endl;
	temp3 = solve2(arr+count,cost,n-count)+cost[2];
	return min(temp1,min(temp2,temp3));
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int* cost = new int[3];
	for(int i=0;i<3;i++)
	{
		cin >> cost[i];
	}
	cout << solve2(arr,cost,n) << endl;
}