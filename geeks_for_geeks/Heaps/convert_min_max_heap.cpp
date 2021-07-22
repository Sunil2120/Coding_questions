#include<bits/stdc++.h>
using namespace std;



void heapify(int* arr,int n,int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<n && arr[l] > arr[largest])
	{
		largest = l;
	}
	if(r<n && arr[r] > arr[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		int temp = arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		heapify(arr,n,largest);
	}
}

void solve(int* arr,int n)
{
	int start = (n/2)-1;
	for(int i=start;i>=0;i--)
	{
		heapify(arr,n,i);
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
	solve(arr,n);
	for(int i=0;i<n;i++)
	{
		cout <<  arr[i] << " ";
	}
	cout << endl;
	return 0;

}