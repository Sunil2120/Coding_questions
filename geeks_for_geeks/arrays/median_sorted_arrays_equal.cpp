#include<bits/stdc++.h>
using namespace std;


int solve2(vector<int>& arr1,int low1,int high1,vector<int>& arr2,int low2,int high2)
{
	int n = high1-low1 + 1;
	if(n==0)
	{
		return -1;
	}
	if(n==1)
	{
		return (arr1[0]+arr2[0])/2;
	}
	if(n==2)
	{
		return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
	}
	int m1,m2;
	if(n%2 == 0)//even
	{
		m1 = (arr1[low1+((n/2)-1)] + arr1[low1+(n/2)])/2;
		m2 = (arr2[low2+((n/2)-1)] + arr2[low2+(n/2)])/2;
		if(m1==m2)
		{
			return m1;
		}
		if(m1 > m2)
		{
			return solve2(arr1,low1,(n/2),arr2,(n/2)-1,high2);
		}
		else
		{
			return solve2(arr1,(n/2)-1,high1,arr2,low2,(n/2));
		}
	}
	else
	{
		m1 = arr1[low1+((n/2))];
		m2 = arr2[low2+((n/2))];
		if(m1==m2)
		{
			return m1;
		}
		if(m1 > m2)
		{
			return solve2(arr1,low1,(n/2),arr2,(n/2),high2);
		}
		else
		{
			return solve2(arr1,(n/2),high1,arr2,low2,(n/2));
		}
	}
		
	return -1;
}

void solve(vector<int>& arr1,vector<int>& arr2,int n)
{
	int result = solve2(arr1,0,n-1,arr2,0,n-1);
	cout << result << endl;
	return ;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr1(n);
	vector<int> arr2(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr1[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> arr2[i];
	}
	solve(arr1,arr2,n);
	return 0;
}