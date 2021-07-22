#include<bits/stdc++.h>
using namespace std;



int kadane(int* arr,int n)
{
	int max = 0;
	int cur =0;
	for(int i=0;i<n;i++)
	{
		cur = cur+ arr[i];
		if(cur<0)
		{
			cur = 0;
		}
		if(cur > max)
		{
			max = cur;
		}
	}
	return max;
}
int main()
{
	int n;
	cin >> n;
	int* arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << kadane(arr,n);
	return 0;
}