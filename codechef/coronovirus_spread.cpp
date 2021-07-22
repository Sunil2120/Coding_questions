#include<bits/stdc++.h>
using namespace std;

void solve(int* arr,int n)
{
	int* count = new int[n];
	for(int i=0;i<n;i++)
	{
		count[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(arr[i]==0 && arr[j]==0)
			{
				continue;
			}
			double t =(double) (i - j)/(arr[j]-arr[i]);
			if(t>=0)
			{
				//cout << i << " " << j << endl;
				count[i]+=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << count[i] << " ";
	}
	cout << endl;
	int min_i = count[0];
	int max_i = count[0];
	for(int i=1;i<n;i++)
	{
		if(count[i] > max_i)
		{
			max_i = count[i];
		}
	}
	for(int i=1;i<n;i++)
	{
		if(count[i] < min_i)
		{
			min_i = count[i];
		}
	}
	cout << min_i << " " << max_i << endl;
	delete[] count;
	return ;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		solve(arr,n);
		delete[] arr;
	}
	return 0;
}