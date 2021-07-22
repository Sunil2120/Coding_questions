#include<bits/stdc++.h>
using namespace std;





long long merge(int a[],int left,int m,int right)
{
	long long sum = 0;
	int i=left;
	int j= m;
	int k=0;
	int temp[right-left+1];
	while(i<m && j<=right)
	{
		if(a[i]<a[j])
		{
			sum+= a[i]*(right+1-j);
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
	}
	while(i<m)
	{
		temp[k++]=a[i++];
	}
	while(j<=right)
	{
		temp[k++]=a[j++];
	}
	for(int i=left,k=0;i<=right;i++,k++)
	{
		a[i]=temp[k];
	}
	return sum;
}


long long merge_sort(int a[],int left,int right)
{
	long long value=0;
	if(right > left)
	{
		int mid = (left+right)/2;
		long long value1= merge_sort(a,left,mid);
		long long value2= merge_sort(a,mid+1,right);
		long long value3= merge(a,left,mid+1,right);
		value = value1 + value2 + value3;
		return value;
	}
	return value;
}

long long solve(int a[],int n)
{
	return merge_sort(a,0,n-1);
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr= new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
		delete []arr;
	}
	return 0;
}