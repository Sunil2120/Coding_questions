#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

void getprimes(bool* primes)
{
	
	for(int i=0;i<=MAX;i++)
	{
		primes[i]=true;
	}
	for(int i=2;i*i<=MAX;i++)
	{
		if(primes[i]==true)
		{
			for(int j=i*i;j<=MAX;j+=i)
			{
				primes[j]=false;
			}
		}
	}
	return ;
}


int main()
{

	bool* primes = new bool[MAX+1];
	getprimes(primes);
	primes[0]=false;
	primes[1]=false;
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int value = arr[i]+arr[j];
			if(primes[value]==false)
			{
				count+=1;
			}
		}
	}
	cout << count << endl;
	delete[] primes;
	return 0;
}