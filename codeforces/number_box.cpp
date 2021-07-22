#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1447/problem/B
//codeforces contest 683 div2 by Meet IT problem B
int solve(int** arr,int n,int m)
{
	int flag = 0;
	int sum = 0;
	int nn=0;
	int min_value = INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] < 0)
			{
				nn+=1;
			}
			if(arr[i][j]==0)
			{
				flag = 1;
			}
			min_value = min(min_value,abs(arr[i][j]));
			sum+=abs(arr[i][j]);
		}
	}
	if(flag==1)//there is atleast 1 zero so using this we can make all negative positive
	{
		return sum;
	}
	if(nn%2 == 0)//number of negative elements is even
	{
		return sum;
	}
	return (sum-(2*min_value));
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		int** arr = new int*[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=new int[m];
			for(int j=0;j<m;j++)
			{
				cin >> arr[i][j];
			}
		}
		cout << solve(arr,n,m) << endl;
		for(int i=0;i<n;i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}