#include<bits/stdc++.h>
using namespace std;




// recurrsion
int min_coins(int value,int* coins,int n)
{
	if(value == 0)
	{
		return 0;
	}

	int res = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(value- coins[i] >=0 )
		{
			int temp = min_coins(value-coins[i],coins,n) ;
			if(temp!=INT_MAX && temp + 1  < res)
			{
				res = temp + 1;
			}
		}
	}
	return res;
}


int min_coins2(int value,int* coins,int n)
{
	int* output = new int[value+1]();
	output[0]=0;
	int min_x = INT_MAX;

	for(int i=1;i<=value;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp ;
			if(i - coins[j]  >=0)
			{
				temp = output[i-coins[j]] + 1;
				if(temp < min_x)
				{
					min_x = temp;
				}
			}
		}
		output[i] = min_x;
		min_x = INT_MAX;
	}

	return output[value];
}





int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	int* coins = new int[m];
	for(int i=0;i<m;i++)
	{
		cin >> coins[i];
	}
	cout << min_coins(n,coins,m);
	return 0;
}