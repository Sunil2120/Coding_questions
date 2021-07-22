#include<bits/stdc++.h>
using namespace std;



int countWaysToMakeChange(int n,int* d,int nd, int** output)// we need 2D array because we are storing two information(n,denominations array size)
{
	// required value is 0 we will return d0 coin
	if(n==0)
	{
		return 1;
	}
	if(nd == 0)// no denomination coins are given
	{
		return 0;
	}
	if( n < 0) 
	{
		return 0;
	}
	if(output[n][nd] > -1)
	{
		return output[n][nd];
	}
	// first we will include d[0]
	int first = coin_change(n-d[0],d,nd,output);
	// we won't consider d[0]
	int second = coin_change(n,d+1,nd-1,output);
	output[n][nd] = first + second;
	return output[n][nd];
}

int main()
{
	int n;
	cin >> n;
	int nd;
	cin >> nd;
	int* deno = new int[nd];
	for(int i=0;i<nd;i++)
	{
		cin >> deno[i];
	}
	// size of 2D array
	// we need n so n+1 and we need nd so nd+1
	int** output = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		output[i]=new int[nd+1];
		for(int k=0;k<=nd;k++)
		{
			output[i][k]= -1;
		}
	}
	cout << coin_change(n,deno,nd,output) << endl;
	delete []deno;
	delete [] output;
	return 0;
}