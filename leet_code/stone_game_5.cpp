#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int start,int end)
{
	if(start >= end)
	{
		return 0;
	}
	int len = end - start + 1;
	int mid = (len/2);
	mid = start + mid - 1;
	int first = arr[mid];
	if(start-1 >= 0)
	{
		first = first - arr[start-1];
	}
	int second = arr[end] - arr[mid];
	cout << first << " " << second << endl;
	int total = 0;
	if(first > second)
	{
		total = second;
		total+=solve(arr,mid+1,end);
	}
	else if(second > first)
	{
		total = first;
		total+=solve(arr,start,mid);
	}
	else
	{
		int f = solve(arr,start,mid);
		int s = solve(arr,mid+1,end);
		total+=max(f,s);
		total+=first;
	}
	return total;
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
	for(int i=1;i<n;i++)
	{
		arr[i]=arr[i-1]+arr[i];
	}
	cout << solve(arr,0,n-1) << endl;
}