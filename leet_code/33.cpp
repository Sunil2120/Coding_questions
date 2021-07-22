#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int start,int end)
{
	if(start==end)
	{
		if(arr[start] > 0)
		{
			return 1;
		}
		return 0;
	}
	int left = start;
	int right = end;
	int negative = 0;
	int count = 0;
	for(int i=start;i<=end;i++)
	{
		if(arr[i] < 0)
		{
			negative+=1;
		}
	}
	//cout << negative << endl;
	while(left < right)
	{
		if((negative%2)!=0)// not even
		{
			if(arr[left] < 0)
			{
				left+=1;
			}
			else if(arr[right] < 0)
			{
				right--;
			}
			else if(arr[left] > 0 && arr[right] > 0 || arr[left] < 0 && arr[right] < 0)
			{
				return max(solve(arr,start+1,end),solve(arr,start,end-1));
			}
		}
		else
		{
			return right-left+1;
		}
	}
	return 0;
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
	cout << solve(arr,0,n-1) << endl;
}