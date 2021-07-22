#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000


bool iscube(int n)
{
	int cu_r = round(cbrt(n));
	if(cu_r*cu_r*cu_r == n)
	{
		return true;
	}
	return false;
}

bool isdiv(int n)
{
	if(iscube(n))
	{
		return false;
	}
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int a = n/i;
			if(iscube(i) || iscube(a))
			{
				return false;
			}
		}
		
	}
	return true;

}

// o(n*square_root of n)
int* solve()
{
	int* arr = new int[MAX+1]();
	arr[1]=1;
	int count = 1;
	for(int i=2;i<=MAX;i++)
	{
		if(isdiv(i))
		{
			count+=1;
			arr[i]=count;
		}
		else
		{
			arr[i]=-1;
		}
	}
	return arr;
	
}
// o(n*log(something) ) this  is less than 10**8

int* solve1()
{
	int* sieve = new int[MAX+1]();
	int count = 1;
	for(int i=2;i<=100;i++) // because(100**3 == 10**6) greater then 100 exceeds the array size
	{
			int temp = i*i*i;
			for(int j=temp ;j<=MAX;j=j+temp)// multiples of j
			{
				sieve[j]=-1;
			}
	}
	int count = 1;
	for(int i=2;i<=MAX;j++)
	{
		if(sieve[i]!=-1)
		{
			sieve[i]=count;
			count+=1;
		}
	}
	return sieve;
}

int main()
{
	int t;
	cin >> t;
	int* output = solve1();
	int count = 1;
	while(t--)
	{
		int n;
		cin >> n;
		cout << "Case " << count << ": ";
		count+=1;

		if(output[n]==-1)
		{
			cout << "Not Cube Free" << endl;
		}
		else
		{
			cout << output[n] << endl;
		}
		
	}
	return 0;
}