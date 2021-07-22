#include<bits/stdc++.h>
using namespace std;



void solve_(int* arr,int n,int* output)
{
	if(n==1)
	{
		output[0]=arr[0];
		return ;
	}
	int lp = 1;
	int rp=1;
	for(int i=0;i<n;i++)
	{
		output[i]=lp;
		lp=lp*arr[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[i]=output[i]*rp;
		rp=rp*arr[i];
	}
	return ;

}



int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* res = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	solve_(arr,n,res);
	for(int i=0;i<n;i++)
	{
		cout << res[i] << " ";
	}
	delete []res;
	delete []arr;
	return 0;
}