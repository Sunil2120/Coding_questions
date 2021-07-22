#include<bits/stdc++.h>
using namespace std;



bool issorted(int* arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(arr[i] > arr[i+1])
		{
			return false;
		}
	}
	return true;
}

void swap(int* a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		if(issorted(arr,n))
		{
			cout << "Yes" << endl;
			delete []arr;
			return 0;
		}
		int i=0;
		int j=i+1;
		while(i<n-1 && j<n)
		{
			if(arr[i] > arr[j])
			{
				swap(&arr[i],&arr[j]);
			}
			i++;
			j++;
		}
		if(issorted(arr,n))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		delete []arr;


	}
}