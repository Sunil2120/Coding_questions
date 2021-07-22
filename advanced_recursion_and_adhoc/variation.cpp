#include<bits/stdc++.h>
using namespace std;



int solve(int arr[], int n,int k)
{
	sort(arr,arr+n);
	int count =0;
	int i=0;
	int j=1;
	while(i<n && j <n)
	{
		if(i==j)
		{
			j++;
		}
		while(abs(arr[i]-arr[j])<k)
		{
			j++;
		}
		count+= n-j;
		i++;
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
	int k;
	cin >> k;
	cout << solve(arr,n,k) << endl;
	return 0;
}