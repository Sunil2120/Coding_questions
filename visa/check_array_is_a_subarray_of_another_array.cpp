#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr1,int n,vector<int>& arr2,int m)
{
	int i=0;
	int j=0;
	while(i<n && j<m)
	{
		if(arr1[i]==arr2[j])
		{
			i+=1;
			j+=1;
			if(j==m)
			{
				return true;
			}
		}
		else
		{
			i = i-j+1;
			j=0;
		}
	}
	return false;
}

int main()
{
	int n,m;
	cin >> n;
	vector<int> arr1(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr1[i];
	}
	cin >> m;
	vector<int> arr2(m);
	for(int i=0;i<m;i++)
	{
		cin >> arr2[i];
	}
	cout << solve(arr1,n,arr2,m) << endl;
	return 0;
}