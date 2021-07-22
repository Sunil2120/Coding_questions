#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int solve(int* arr,int n)
{
	long long** output = new long long*[n];
	for(int i=0;i<n;i++)
	{
		output[i]= new long long[100+1]();
	}

	for(int i=0;i<n;i++)
	{
		output[i][arr[i]]+=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j] < arr[i])
			{
				for(int k=0;k<=100;k++)
				{
					if(output[j][k] > 0)// there is sequence of k GCD
					{
						int G = __gcd(k,arr[i]);
						output[i][G] = (output[i][G] + output[j][k]);
						output[i][G] = output[i][G]%MOD;

					}
				}
			}
		}	
	}
	long long sum=0;
	for(int i=0;i<n;i++)
	{

		sum= sum + output[i][1];
		sum = sum%MOD;
	}
	delete[] output;
	// sum is long long so converting it to int
	return sum;
}


int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >>  input[i]; 
	}
	cout << solve(input,n) << endl;
	delete []input;
	return 0;
}