#include<bits/stdc++.h>
using namespace std;



int solve(vector<int>& arr1,int n,vector<int>& arr2,int m)
{
	if(n==0 && m==0)
	{
		return 0;
	}
	if(n==0)
	{
		int total=0;
		for(int i=0;i<m;i++)
		{
			total+=arr2[i];
		}
		return total;
	}
	if(m==0)
	{
		int total=0;
		for(int i=0;i<n;i++)
		{
			total+=arr1[i];
		}
		return total;
	}
	int i=0;
	int j=0;
	int sum1=0;
	int sum2=0;
	int total = 0;
	while(i<n && j<m)
	{
		if(arr1[i]==arr2[j])
		{
			sum1+=arr1[i];
			sum2+=arr2[j];
			total+=max(sum1,sum2);
			sum1=0;
			sum2=0;
			i++;
			j++;
		}
		else if(arr1[i] < arr2[j])
		{
			sum1+=arr1[i];
			i++;
		}
		else
		{
			sum2+=arr2[j];
			j++;
		}
	}
	while(i<n)
	{
		sum1+=arr1[i];
		i++;
	}
	while(j<m)
	{
		sum2+=arr2[j];
		j++;
	}
	total+=max(sum1,sum2);
	return total;

}
int main()
{
	while(true)
	{
		int n;
		cin >> n;
		if(n==0)
		{
			break;
		}
		vector<int> arr1(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr1[i];
		}
		int m;
		cin >> m;
		vector<int> arr2(m);
		for(int i=0;i<m;i++)
		{
			cin >> arr2[i];
		}
		cout << solve(arr1,n,arr2,m) << endl;
	}
	return 0;
}