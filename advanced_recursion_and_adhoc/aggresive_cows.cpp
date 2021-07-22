#include<bits/stdc++.h>
using namespace std;



bool check(int a,int n,vector<int> arr)
{
	//cout << "hello " << endl;
	int position = arr[0];
	int count = 1;
	for(int i=1;i<arr.size();i++)
	{
		
		if(arr[i] - position >=a)
		{
			position = arr[i];
			count+=1;
		}
		if(count == n)
		{
			//cout << count << endl;
			return true;
		}
	}
	return false;

}
int solve_(int n,vector<int> arr)
{
	//cout << "hello " << endl;
	sort(arr.begin(),arr.end());
	int start = 0;
	int end = arr[arr.size()-1] - arr[0];
	int mid = (abs(end-start))/2;
	if(check(mid,n,arr))
	{
		int d=mid+1;
		for(int i=d;i<=end;i++)
		{
			if(check(i,n,arr))
			{
				continue;
			}
			else
			{
				return i-1;
			}
		}
	}
	else
	{
		int d = mid-1;
		for(int i=start;i<=mid-1;i++)
		{
			if(check(i,n,arr))
			{
				continue;
			}
			else
			{
				return i-1;
			}
		}
		return mid-1;
	}
	return -1;
	
}

// int solve_2(int n,vector<int> arr,int start,int end)
// {
// 	int mid = (start+end)/2;
// 	if(start==end)
// 	{
// 		return arr[start];
// 	}
// 	if(check(arr[mid],n,arr))
// 	{
// 		return solve_2(n,arr,mid+1,end);
// 	}
// 	else
// 	{
// 		return solve_2(n,arr,start,mid-1);
// 	}
// 	return -1;
// }

// int minD(vector<int> arr,int n)
// {
// 	sort
// }


int solve_2(vector<int> arr,int c,int start,int end,vector<int> d)
{
	int mid = (start+end)/2;
	if(start==end)
	{
		return d[start];
	}
	if(check(d[mid],c,arr))
	{
		return solve_2(arr,c,mid+1,end,d);
	}
	else
	{
		return solve_2(arr,c,start,mid-1,d);
	}
}
int m(vector<int> arr,int c)
{
	sort(arr.begin(),arr.end());
	vector<int> d;
	int end = (arr[arr.size()-1] - arr[0]);
	for(int i=0;i<=end;i++)
	{
		d.push_back(i);
	}
	return solve_2(arr,c,0,d.size()-1,d);

}

int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	while(n--)
	{
		int s;
		cin >> s;
		int no_cow;
		cin >> no_cow;
		for(int i=0;i<s;i++)
		{
			int x;
			cin >> x;
			arr.push_back(x);
		}
		cout << m(arr,no_cow) -1 << endl;
	}
	// int test;
	// cin >> test;

	// for(int i=0;i<test;i++)
	// {
	// 	int n;
	// 	cin >> n;
	// 	int co;
	// 	cin >> co;
	// 	for(int i=0;i<n;i++)
	// 	{
	// 		cin >> arr[i];
	// 	}
	// 	// if(check(9,3,arr))
	// 	// {
	// 	// 	cout << "true" << endl;
	// 	// }
	// 	// else
	// 	// {
	// 	// 	cout << "false" << endl;
		
	// 	// cout << solve_(3,arr) << endl;
	// 	cout << solve_(co,arr) << endl;
	// }
	//cout << solve_(3,arr);
	
	return 0;
}