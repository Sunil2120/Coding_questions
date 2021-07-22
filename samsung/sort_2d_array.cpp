#include<bits/stdc++.h>
using namespace std;

void merge_sort(int** arr,int row,int low,int mid,int high)
{
	int n1 = mid-low + 1;
	int n2 = high - (mid+1) + 1;
	int l[n1],r[n2];
	for(int i=0;i<n1;i++)
	{
		l[i]=arr[row][low+i];
	}
	for(int i=0;i<n2;i++)
	{
		r[i]=arr[row][mid+1+i];
	}
	int i=0;
	int j= 0;
	int k = low;
	while(i<n1 && j < n2)
	{
		if(l[i] <= r[j])
		{
			arr[row][k]=l[i];
			i++;
			k++;
		}
		else
		{
			arr[row][k]=r[j];
			j++;
			k++;

		}
	}
	while(i<n1)
	{
		arr[row][k]=l[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[row][k]=r[j];
		j++;
		k++;
	}
	return ;
}


void merge(int** arr,int row,int low,int high)
{
	if(low < high)
	{
		int mid = low + (high-low)/2;

		merge(arr,row,low,mid);
		merge(arr,row,mid+1,high);
		merge_sort(arr,row,low,mid,high);
	}
	return ;
}
int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		merge(arr,i,0,n-1);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}