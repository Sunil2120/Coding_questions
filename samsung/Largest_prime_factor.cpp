#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int n)
{
	if(n==0)
	{
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(arr[i]==INT_MIN)//prime
		{
			for(int j=1;j*i<=n;j++)
			{
				arr[j*i]=max(arr[j*i],i);
			}
		}
	}
	
	return arr[n];
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		arr[i]=INT_MIN;
	}
	cout << solve(arr,n) << endl;
	return 0;
}