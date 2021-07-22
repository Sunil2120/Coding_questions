#include<bits/stdc++.h>
using namespace std;


int max_product(int* arr,int n)
{
	if(n==1)
	{
		return arr[0];
	}
	int max_sub=1;
	int min_sub=1;
	int max_total =INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			max_sub*=arr[i];//max_sub becomes more positive
			min_sub = min(1,min_sub*arr[i]);// min_sub becomes more negative
		}
		else if(arr[i] < 0)
		{
			int temp = max_sub;
			max_sub = max(1,min_sub*arr[i]);
			min_sub = temp*arr[i];
		}
		else
		{
			max_sub = 1;
			min_sub =1;
		}
		if(max_sub > max_total)
		{
			max_total = max_sub;
		}
	}
	return max_total;
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
	cout << max_product(arr,n) << endl;
	delete []arr;
	return 0;
}