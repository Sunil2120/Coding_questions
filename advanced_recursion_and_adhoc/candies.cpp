#include<bits/stdc++.h>
using namespace std;





// int solve(int arr[],int n,int k)
// {
// 	sort(arr,arr+n);
// 	int start =0;
// 	int end = arr[n-k];

// 	int mid = (start+end)/2;
// 	if(check(arr,n,k,mid))
// 	{
// 		int d = mid+1;

// 	}
// }

bool check(int arr[],int n,int k,int d)
{
	int count =0;
	for(int i=0;i<n;i++)
	{
		count+=(arr[i])/d;
		if(count >= k)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k,n;
		cin >> n >> k;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		sort(arr,arr+n);
		int left=0;
		int right = arr[n-1];
		int ans =0;
		while(left <= right)
		{
			int mid = (left+right)/2;
			if(check(arr,n,k,mid))
			{
				ans = mid;
				left=mid+1;
			}
			else
			{
				right = mid-1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}