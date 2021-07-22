#include<bits/stdc++.h>
using namespace std;

int sqrt1(int value)
{
	
	int ans = 0;
	for(int i=1;i*i<=value;i++)
	{
		ans = i;
	}
	return ans;
}

bool ispossible(int value,int n,int m,vector<int>& arr)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		// how many paratas i chef will prepare in value time
		int a  = -1*arr[i];
		int b = (arr[i]*arr[i]) + (4*arr[i]*2*value);
		int c = 2*arr[i];
		int temp = (a + sqrt1(b))/c;
		count+=temp;
	}
	if(count >= m)
	{
		return true;
	}
	return false;
}


int solve(vector<int>& arr,int n,int m)
{
	int low = 0;
	int high = (m*(2*arr[n-1] + (m-1)*arr[n-1]))/2;
	int ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(ispossible(mid,n,m,arr))
		{
			ans = mid;
			// we need minimum
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m,n;
		cin >> m >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n,m) << endl;
	}
	return 0;
}