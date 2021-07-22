#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int key,int n)
{
	int count = 0;
	int sum = 0;
	for(int i=0;i<(1<<n);i++)
	{
		sum = 0;

		// check which bit is set
		for(int j = 0;j<n;j++)
		{
			if((i&(1<<j))!=0)// bit is set
			{
				sum+=arr[j];
			}
		}
		// cout << sum << endl;
		if(sum==key)
		{
			count++;
		}
	}
	return count;
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
	int key;
	cin >> key;
	cout<< solve(arr,key,n) << endl;
}