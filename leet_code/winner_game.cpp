#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int n,int k)
{
	if(k>n)// largest number will remain at first position and wins max number of times consecutively
	{
		int largest = INT_MIN;
		for(int  i=0;i<n;i++)
		{
			largest = max(arr[i],largest);
		}
		return largest;
	}
	int cur =arr[0];
	int rp = 0;
	for(int i=1;i<n;i++)
	{
		if(arr[i] > cur)
		{
			cur = arr[i];
			rp=0;
			continue;
		}
		rp+=1;
		if(rp==k)
		{
			break;
		}
	}
	return cur;
}
int main()
{
	int n,k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
	return 0;
}