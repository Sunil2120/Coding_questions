#include<bits/stdc++.h>
using namespace std;


void merge(int* arr,int low,int mid,int high)
{
	int n1 = mid-low + 1;
	int n2 = high-(mid+1) + 1;
	int l[n1];
	int r[n2];
	// copy
	for(int i=0;i<n1;i++)
	{
		l[i]=arr[low+i];
	}
	for(int i=0;i<n2;i++)
	{
		r[i]=arr[mid+1+i];
	}
	int i=0;
	int j=0;
	int k=low;
	while(i<n1 && j<n2)
	{
		if(l[i] < r[j])
		{
			arr[k]=l[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=r[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=l[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=r[j];
		j++;
		k++;
	}
	return ;
}


void merge2(int* arr,int low,int mid,int high)
{
	int n1 = mid-low + 1;
	int n2 = high-(mid+1) + 1;
	int l[n1];
	int r[n2];
	// copy
	for(int i=0;i<n1;i++)
	{
		l[i]=arr[low+i];
	}
	for(int i=0;i<n2;i++)
	{
		r[i]=arr[mid+1+i];
	}
	int i=0;
	int j=0;
	int k=low;
	while(i<n1 && j<n2)
	{
		if(l[i] > r[j])
		{
			arr[k]=l[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=r[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=l[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=r[j];
		j++;
		k++;
	}
	return ;
}

void ascending(int* arr,int low,int high)
{
	if(low < high)
	{
		int mid = low + (high-low)/2;
		ascending(arr,low,mid);
		ascending(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	return ;
}
void descending(int* arr,int low,int high)
{
	if(low < high)
	{
		int mid = low + (high-low)/2;
		descending(arr,low,mid);
		descending(arr,mid+1,high);
		merge2(arr,low,mid,high);
	}
	return ;
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
	int k;
	cin >> k;
	if(k>=n)
	{
		ascending(arr,0,n-1);
		for(int i=0;i<n;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return 0;
	}
	int high = k+0-1;
	ascending(arr,0,high);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	descending(arr,high+1,n-1);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	delete[] arr;
}