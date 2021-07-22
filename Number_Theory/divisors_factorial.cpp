// here we are finding the number of divisior of n!
// in naive apporach time will be very large o(n!) which is not acceptable
// every number can be expressed as N = p1**a.p2**b.p3**c_ _ _ where p1,p2,p3 etc are the prime numbers within N
// to get the no of divisors of N (a+1)*(b+1)*(c+1)_ _ _
// to get the power of p1 in N!
// power of p1 in N! = N/p1 + N/p1**2 + N/p1**3 _ _ _ until p1**k <= N so we will do this until N/p1**k becomes 0
// we get the power ans = (a1+1)*(a2+1)*(a3*1) etc

#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
#define MOD 1000000007

void seive(vector<int>& primes)
{
	bool* arr = new bool[MAX+1];
	for(int i=0;i<=MAX;i++)
	{
		arr[i]=true;
	}
	arr[0]=false;
	arr[1]=false;
	for(int i=2;i*i<=MAX;i++)
	{
		if(arr[i]==true)
		{
			for(int j=i*i;j<=MAX;j+=i)
			{
				arr[j]=false;
			}
		}
	}
	primes.push_back(2);
	// even numbers cannot be prime expect 2
	for(int i=3;i<=MAX;i=i+2)
	{
		if(arr[i]==true)
		{
			primes.push_back(i);
		}

	}
	delete[] arr;
	return ;
}

int num_divisors(int n)
{
	vector<int> primes;
	seive(primes);
	long long ans = 1;
	// to get power of this primes in n!
	for(int i=0;primes[i]<=n;i++)
	{
		long long count = 0;
		long long k = primes[i];
		// while(k<=n)
		// {
		// 	count = count + (n/k);
		// 	count = count%MOD;
		// 	k = k*k;
		// }
		while((n/k)!=0)
		{
			count = count + (n/k);
			count = count%MOD;
			k=k*k;
		}
		// if k becomes greater than n then (n/k) becomes 0
		ans = ans*(count+1);
		ans = ans%MOD;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << num_divisors(n) << endl;
	}
	return 0;
}