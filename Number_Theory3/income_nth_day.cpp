// income on nth day
// f(n) = f(n-1) + f(n-2) + f(n-1)*f(n-2)
#include<bits/stdc++.h>
using namespace std;
#define  MOD 1000000007
typedef long ll;


void multiply(ll A[2][2],ll M[2][2])
{
	ll fvalue = A[0][0]*M[0][0]%(MOD-1) + A[0][1]*M[1][0]%(MOD-1);
	ll svalue = A[0][0]*M[0][1]%(MOD-1) + A[0][1]*M[1][1]%(MOD-1);
	ll tvalue = A[1][0]*M[0][0]%(MOD-1) + A[1][1]*M[1][0]%(MOD-1);
	ll lvalue = A[1][0]*M[0][1]%(MOD-1) + A[1][1]*M[1][1]%(MOD-1);
	A[0][0]=fvalue%(MOD-1);
	A[0][1]=svalue%(MOD-1);
	A[1][0]=tvalue%(MOD-1);
	A[1][1]=lvalue%(MOD-1);
	return ;
}


int power3(ll a,ll b,ll c)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	ll value = power3(a,b/2,c);
	ll ans;
	if((b%2)==0)// b is even
	{
		ans = value*value;
		ans = ans%c;
	}
	else // b is odd
	{
		ans = value*value;
		// a can be large too
		ans = ans*(a%c);
		ans = ans%c;
	}
	// ans can be negative
	return (int)(ans+c)%c;
}

void power(ll A[2][2],int n)
{
	// base case
	if(n==0 || n==1)
	{
		return ;
	}
	//this will give A^n/2
	power(A,n/2);
	// mutliply A^n/2 * A^n/2
	if(n%2==0)
	{
		multiply(A,A);
	}
	// n is even A^n/2 * A^n/2 is the answer
	else// n is odd
	{
		// if n is odd A^n/2 * A^n/2 * A is the answer
		ll M[2][2]={{1,1},{1,0}};
		multiply(A,A);
		multiply(A,M);
	}
	return ;

}

int fib(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	ll A[2][2]={{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}


int solve(int f0,int f1,int n)
{
	ll a = 1 + f0;
	ll b = 1 + f1;
	ll fvalue = power3(a,(fib(n-1)%(MOD - 1)),MOD);
	ll svalue = power3(b,(fib(n)%(MOD-1)),MOD);
	ll ans = (fvalue*svalue)%MOD;
	ans =  (ans  -1);
	return (ans+MOD)%MOD;
}




int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int f0,f1,n;
		cin >> f0 >> f1 >> n;
		cout << solve(f0,f1,n) << endl;
	}
}