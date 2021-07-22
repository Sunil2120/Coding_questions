#include<bits/stdc++.h>
using namespace std;


int max_profit(int* input,int n,int k,bool ongoing)
{
	if(n==0)
	{
		return 0;
	}
	if(k<=0)
	{
		return 0;
	}
	// ignore
	int temp = max_profit(input+1,n-1,k,ongoing);
	// include
	if(ongoing)
	{
		// sell
		int temp2 = max_profit(input+1,n-1,k-1,false) + input[0];
		return max(temp,temp2);
	}
	// buy
	int temp3 = max_profit(input+1,n-1,k,true) - input[0];
	return max(temp,temp3);
}

int max_profit2(int* input,int n,int k,int ongoing,int*** output)
{
	if(n==0)
	{
		return 0;
	}
	if(k<=0)
	{
		return 0;
	}
	if(output[n][k][ongoing] > -1)
	{
		return output[n][k][ongoing];
	}
	int temp = max_profit2(input+1,n-1,k,ongoing,output);
	if(ongoing)
	{
		//sell
		int temp2 = max_profit2(input+1,n-1,k-1,0,output) + input[0];
		output[n][k][ongoing]=max(temp,temp2);
	}
	else
	{
		int temp3=max_profit2(input+1,n-1,k,1,output) - input[0];
		output[n][k][ongoing]=max(temp,temp3);

	}
	return output[n][k][ongoing];

}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> k;
		cin >> n;
		int* input = new int[n];
		int*** output = new int**[n+1];
		for(int i=0;i<=n;i++)
		{
			output[i]=new int*[k+1];
			for(int j=0;j<=k;j++)
			{
				output[i][j]=new int(2);
				for(int k=0;k<2;k++)
				{
					output[i][j][k]=-1;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			cin >> input[i];
		}
		cout << max_profit(input,n,k,false) << endl;
		cout << max_profit2(input,n,k,0,output) << endl;
	}

	return 0;
}