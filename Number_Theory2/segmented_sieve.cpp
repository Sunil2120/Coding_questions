// we should print prime numbers within given L and R inclusive
// R can be very large
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

// r can be max 10**10 
// in below function we are storing primes till square root of r 10**5
// if we know the prime till square root of r then we can know the primes till r

void segmented_sieve(vector<int>& primes)
{
	bool* sieve = new bool[MAX+1];
	for(int i=0;i<=MAX;i++)
	{
		sieve[i]=true;
	}
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;i*i<=MAX;i++)
	{
		if(sieve[i]==true)// its a prime
		{
			// making all its multiple  false
			for(int j=i*i;j<=MAX;j+=i)
			{
				sieve[j]=false;
			}
		}
	}
	for(int i=2;i<=MAX;i++)
	{
		if(sieve[i]==true)// it is a prime
		{
			primes.push_back(i);
		}
	}
	delete[] sieve;
	return ;

}

void getprimes(long long l,long long r,vector<int> primes)
{
	bool* arr = new bool[r-l+1];
	for(int i=0;i<=(r-l);i++)
	{
		arr[i]=true;
	}
	// get primes which are less than square_root of r
	for(int i=0;primes[i]*(long long)primes[i] <= r;i++)
	{
		long long cur_p = primes[i];
		// get the nearest value of l which is multiple of cur prime
		long long base = (l/primes[i])*primes[i];
		if(base < l)
		{
			base = base + cur_p;
		}
		for(int i=base;i<=r;i+=cur_p)
		{
			arr[i-l]=false;
		}
		if(base==cur_p)// base can be cur_p also in some case ex(2/3 * 3 = 0 less than l 0+3 = 3  and in forloop
						//		it will make it as false)
		{
			arr[base-l]=true;
		}
		if(l==1)// if l =1 1 is not a prime number of arr[0+1] is not a prime
		{
			arr[0]=false;
		}
	}


	for(int i=0;i<=(r-l);i++)
	{
		if(arr[i]==true)
		{
			cout << i+l << " ";
		}
	}
	cout << endl;
	delete[] arr;
	return ;
}

int main()
{
	vector<int> primes;
	segmented_sieve(primes);
	int t;
	cin >> t;
	while(t--)
	{
		long long l,r;
		cin >> l >> r;
		getprimes(l,r,primes);
	}
	return 0;
}