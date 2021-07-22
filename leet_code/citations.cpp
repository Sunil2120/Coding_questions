#include<bits/stdc++.h>
using namespace std;

bool check(int* arr,int n,int index)
{
	int count = 0;
	int* temp = new int[n];
	for(int i=0;i<n;i++)
	{
		temp[i]=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		if(temp[i]>=index)
		{
			count+=1;
			temp[i]=-1;
		}
		if(count==index)
		{
			break;
		}
	}
	int count2 = 0;
	for(int i=0;i<n;i++)
	{
		if(temp[i]!=-1 && temp[i]<=index)
		{
			count2+=1;
		}
	}
	delete[] temp;
	if(count==index && count2==(n-index))
	{
		return true;
	}
	
	return false;
}


int solve(int* arr,int n)
{
	int max_ = 0;
	sort(arr,arr+n,greater<>());
	for(int i=0;i<=n;i++)
	{
		if(check(arr,n,i))
		{
			max_ = max(i,0);
		}
	}
	return max_;
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
	cout << solve(arr,n) << endl;
	return 0;
}