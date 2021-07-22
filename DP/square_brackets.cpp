#include<bits/stdc++.h>
using namespace std;


int no_ways(int n,int open,int close,bool* check)
{
	// base case
	if(n==0)
	{
		return 0;
	}
	if(open > n || close > n)
	{
		return 0;
	}
	if(open==n && close==n)
	{
		return 1;
	}
	if(open==close || check[open+close])// compulsory condition to put opening bracket
	{
		return no_ways(n,open+1,close,check);
	}
	if(open==n)
	{
		return no_ways(n,open,close+1,check);
	}
	
	int temp = no_ways(n,open+1,close,check);
	int temp1 = no_ways(n,open,close+1,check);
	return temp+temp1;

}


int no_ways2(int n,int open,int close,bool* check,int** output)
{
	if(n==0)
	{
		return 1;
	}
	if(open > n || close > n)
	{
		return 0;
	}
	if(output[open][close] > -1)
	{
		return output[open][close];
	}
	if(open==n && close==n)
	{
		return 1;
	}
	if(open==close || check[open+close])
	{
		output[open][close]=no_ways2(n,open+1,close,check,output);
		return output[open][close];
	}
	else
	{
		if(open==n)
		{
			output[open][close]=no_ways2(n,open,close+1,check,output);
			return output[open][close];
		}
	}
	int temp = no_ways2(n,open+1,close,check,output);
	int temp1 = no_ways2(n,open,close+1,check,output);
	output[open][close]=temp1 + temp;
	return output[open][close];
}

int main()
{
	int d;
	cin >> d;
	while(d--)
	{
		int n,k;
		cin >> n >> k;
		int* input = new int[k];
		bool* check = new bool[2*n];
		int** output = new int*[n+1];
		for(int i=0;i<=n;i++)
		{
			output[i]=new int[n+1];
			for(int j=0;j<=n;j++)
			{
				output[i][j]=-1;
			}
		}
		for(int i=0;i<2*n;i++)
		{
			check[i]=false;
		}
		for(int i=0;i<k;i++)
		{
			cin >> input[i];
			check[input[i]-1]=true;
		}
		cout << no_ways(n,0,0,check) << endl;
		cout << no_ways2(n,0,0,check,output) << endl;
		delete[] input;
		delete[] check;
		for(int i=0;i<=n;i++)
		{
			delete[] output[i];
		}
		delete[] output;
	}
	return 0;
}