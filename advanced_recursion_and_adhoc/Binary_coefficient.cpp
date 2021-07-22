#include<bits/stdc++.h>
using namespace std;



int BC(int n,int k)
{

	if(k==0 || k==n)
	{
		return 1;
	}
	int* arr = new int[k+1];
	for(int i=0;i<k+1;i++)
	{
		arr[i]=0;
	}
	if(arr[k]!=0)
	{
		return arr[k];
	}
	arr[k] = BC(n-1,k) + BC(n-1,k-1);
	return arr[k];
}

int main()
{
	cout << BC(100,95) << endl;
	return 0;
}