#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int low,int mid,int high,int& count)
{
	int n1 = mid-low+1;
	int m1 = high-(mid+1)+1;
	int i=0;
	int L[n1];
	int R[m1];
	int j=0;
	int k=low;
	for(int i=low;i<=mid;i++)
	{
		L[i-low]=arr[i];
	}
	for(int i=mid+1;i<=high;i++)
	{
		R[i-(mid+1)] = arr[i];
	}
	while(i<n1 && j<m1)
	{
		if(L[i] <= R[j])
		{
			arr[k]=L[i];
			i+=1;
			k+=1;
		}
		else
		{
			count+=(n1-i);
			arr[k]=R[j];
			j+=1;
			k+=1;
		}
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i+=1;
		k+=1;
	}
	while(j<m1)
	{
		arr[k]=R[j];
		j+=1;
		k+=1;
	}
	return ;

}

void mergesort(vector<int>& arr,int low,int high,int& count)
{
	if(low < high)
	{
		int mid = (low)+(high-low)/2;
		mergesort(arr,low,mid,count);
		mergesort(arr,mid+1,high,count);
		merge(arr,low,mid,high,count);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int count=0;
	mergesort(arr,0,n-1,count);
	cout << count << endl;
	return 0;
}