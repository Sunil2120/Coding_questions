// to get pow(a,b) iteratively
// o(log(b))
// we will express b in its binary representation and do the operation accordingly
#include<bits/stdc++.h>
using namespace std;


int pow_iter(int a,int b,int c)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	long ans = 1;
	long prev = a;
	while(b!=0)
	{
		if((b%2)==1)// check right most bit of b
		{
			// multiplying 2**(bit position)
			ans = ans*prev;
			ans = ans%c;
		}
		prev=prev*prev;
		prev = prev%c;
		b=b/2;
	}
	return (int)ans;
}

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << pow_iter(a,b,c) << endl;
	return 0;
}