#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]+arr[j]==0)
			{
				cout << arr[i] << " " << arr[j] << endl;
			}
		}
	}
	return 0;
}