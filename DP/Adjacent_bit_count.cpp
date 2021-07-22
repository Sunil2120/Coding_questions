#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007




int ABC(int n,int k,int first,int** zeros,int** ones)
{

	if(n==1)
	{
		if(k==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(k < 0)
	{
		return 0;
	}
	if(first == 0)
	{
		if(zeros[n][k]>-1)
		{
			return zeros[n][k];
		}
	}
	else if(first == 1)
	{
		if(ones[n][k] > -1)
		{
			return ones[n][k];
		}
	}
	long long sum = 0;
	if(first == 0)
	{
		sum = ABC(n-1,k,0,zeros,ones) + ABC(n-1,k,1,zeros,ones);
		zeros[n][k]=sum%MOD;
	}
	else if(first == 1)
	{
		sum = ABC(n-1,k,0,zeros,ones) + ABC(n-1,k-1,1,zeros,ones);
		ones[n][k] = sum%MOD;
	}

	return sum%MOD;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k,s;
		cin >> s >> n >> k;
		int** zeros = new int*[n+1];
		for(int i=0;i<=n;i++)
		{
			zeros[i]= new int[k+1];
			for(int j=0;j<=k;j++)
			{
				zeros[i][j]=-1;
			}
		}

		int** ones = new int*[n+1];
		for(int i=0;i<=n;i++)
		{
			ones[i]= new int[k+1];
			for(int j=0;j<=k;j++)
			{
				ones[i][j]=-1;
			}
		}

		long long value;
		value = ABC(n,k,0,zeros,ones) + ABC(n,k,1,zeros,ones);
		value = value%MOD;
		cout << s << " " <<   value << endl;

	}
	
	return 0;
}