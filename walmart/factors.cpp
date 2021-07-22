#include<bits/stdc++.h>
using namespace std;

int product_factors(int n)
{
	int total = 1;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
			{
				total = total*i;
			}
			else
			{
				total = total*i*(n/i);
			}
		}
	}
	return total;
}

long long prime_factors(int n)
{
	long long* dp = new long long[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=1;
	}
	for(int i=2;i*i<=n;i++)
	{
		if(dp[i]==1)//prime
		{
			for(int j=1;j*i<=n;j++)
			{
				dp[j*i]=dp[j*i]*i;
			}
		}
	}
	long long ans =  dp[n];
	delete[] dp;
	return ans;
}

int count_prime_factors(int n)
{
	int total = 0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
			{
				total+=1;
			}
			else
			{
				total+=2;
			}
		}
	}
	return total;
}


int main()
{
	int A;
	cin >> A;
	int B = product_factors(A);
	int C = prime_factors(B);
	int D = count_prime_factors(C);
	cout << D << endl;
	return 0;
}