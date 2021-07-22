// to find the number of prime numbers frome 1 to N
#include<bits/stdc++.h>
using namespace std;



bool checkprime(int value)
{
	int count = 0;
	for(int i=1;i<=value;i++)
	{
		if((value%i)==0)
		{
			count++;
		}
	}
	if(count==2)// for prime numbers number of factors is only two(1 and number itself)
	{
		return true;
	}
	return false;
}

// naive method o(n*n)
int solve(int N)
{
	int count = 0;
	for(int i=1;i<=N;i++)
	{
		if(checkprime(i))// o(n)
		{
			count+=1;
		}
	}
	return count;
}


bool checkprime1(int value)
{
	// we are going only till square of value  (because if both multiplicant and multipliers are factors of result)
	int count = 0;
	for(int i=1;i*i<=value;i++)
	{
		if((value%i)==0)// value is divisible by i (i is a factor of value)
		{
			if(i*i==value)
			{
				count+=1;
			}
			else
			{
				count+=2;
			}
		}
	}
	if(count==2)
	{
		return true;
	}
	return false;
}


// optimized solution-1 o(n*square_root(n))
int solve1(int N)
{
	int count = 0;
	for(int i=1;i<=N;i++)
	{
		if(checkprime1(i))// o(square_root(n))
		{
			count+=1;
		}
	}
	return count;
}

// most optimized solution-2 o(n*log(log(n)/2))
int solve2(int N)
{
	bool* sieve = new bool[N+1];
	int count =0;
	for(int i=0;i<=N;i++)
	{
		sieve[i]=true;
	}
	sieve[0]=false;
	sieve[1]=false;
	// we are going till square root of square_root(n) 
	// from i we are starting from i*i  going till n so i*i<=n (squaring on b.s i<=square_root(n))
	for(int i=2;i*i<=N;i++)
	{
		if(sieve[i]==true)
		{
			for(int j=i*i;j<=N;j+=i)
			{
				sieve[j]=false;
			}
		}
	}
	// counting number of  true
	for(int i=0;i<=N;i++)
	{
		if(sieve[i]==true)
		{
			count+=1;
		}
	}
	delete[] sieve;
	return count;
}

int main()
{
	int N;
	cin >> N;
	cout << solve2(N) << endl;
	cout << solve(N) << endl;
	cout << solve1(N) << endl;
	return 0;
}