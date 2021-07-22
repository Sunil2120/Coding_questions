// Euler_totient function is used to number of co-primes of n  which are less than n
// co-prime gcd(a,b)=1 a and b are co-primes
// Euler_totient fuction is used to get all elements less than n whose gcd with n is 1
// formula Euler_func(n) = n*[(1-1/p1).(1-1/p2).(1-1/p3)_ _ _ (1-1/pk)] k is number of distinct prime factors of n
#include<bits/stdc++.h>
using namespace std;

// this function prints the co-primes of all elements from 1 to n
void Euler_totientphi(int n)
{
	int phi[n+1];
	for(int i=1;i<=n;i++)
	{
		phi[i]=i;
	}
	phi[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(phi[i]==i)// this is a prime number 
		{
			phi[i]=i-1;// co-primes of prime number is prime number -1 
			// multiple all its multiple by (i-1)/i 
			for(int j=2;j*i<=n;j++)
			{
				phi[j*i]=(phi[j*i]*(i-1))/i;
			}
		}
	}
	// printing
	for(int i=1;i<=n;i++)
	{
		cout << i << " " << phi[i] << endl;
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	Euler_totientphi(n);
	return 0;
}