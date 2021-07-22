// to find gcd of two numbers
#include<bits/stdc++.h>
using namespace std;



//naive apporach o(min(a,b))
int gcd(int a,int b)
{
	int value = 0;
	for(int i=1;i<=(min(a,b));i++)
	{
		if(a%i==0 && b%i==0)// i is divisor of both a,b
		{
			value = i;
		}
	}
	return value;
}

// Euclid's Algorithm to find gcd(a,b)
// a>b mandatory condition
// gcd(a,b)=gcd(b,a%b) 
// time complexity o(log(max(a,b)))
int gcd2(int a,int b)
{
	if(b>a)
	{
		return gcd2(b,a);
	}
	if(b==0) // gcd(n,0)==n (gcd with 0 is always n)
	{
		return a;
	}
	return gcd2(b,a%b);
}


int main()
{
	int a,b;
	cin >> a >> b;
	cout << gcd2(a,b) << endl;
	cout << gcd(a,b) << endl;
	return 0;
}