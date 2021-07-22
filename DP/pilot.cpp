#include<bits/stdc++.h>
using namespace std;


int min_cost(int n,int* captain,int* assis,int x)// x is difference of assistants and captains
{
	if(n<=0)
	{
		return 0;
	}

	if(x==0)// no captains no assistant and he is the younger
	{
		return min_cost(n-1,captain+1,assis+1,1)+assis[0];// we included one assistant
	}

	else if(x==n) // only n people are left and we have n assistant so rest of them has to be captain to componset
	{
		return min_cost(n-1,captain+1,assis+1,x-1)+captain[0];// we just included the caption
	}

	int temp = min_cost(n-1,captain+1,assis+1,x+1) + assis[0];
	int temp1 = min_cost(n-1,captain+1,assis+1,x-1) + captain[0];
	return min(temp,temp1);	

}

int min_cost2(int n,int* captain,int* assis,int x,int** output)
{
	if(n<=0)
	{
		return 0;
	}
	if(output[n][x] > -1)
	{
		return output[n][x];
	}
	if(x==0)
	{
		output[n][x]=min_cost2(n-1,captain+1,assis+1,1,output) + assis[0];
	}
	else if(x==n)
	{
		output[n][x]=min_cost2(n-1,captain+1,assis+1,x-1,output) + captain[0];
	}
	else
	{
		int temp = min_cost2(n-1,captain+1,assis+1,x+1,output) + assis[0];
		int temp1 = min_cost2(n-1,captain+1,assis+1,x-1,output) + captain[0];
		output[n][x]=min(temp,temp1);
	}
	return output[n][x];
}

int main()
{
	int n;
	cin >> n;
	int* ca = new int[n];
	int* as = new int[n];
	int** output = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		output[i]=new int[n/2 + 1];
		for(int j=0;j<=n/2;j++)
		{
			output[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin >> ca[i] >> as[i];
	}
	cout << min_cost2(n,ca,as,0,output) << endl;
	for(int i=0;i<=n;i++)
	{
		delete[] output[i];
	}
	delete[] output;
	delete[] ca;
	delete[] as;
	return 0;
}