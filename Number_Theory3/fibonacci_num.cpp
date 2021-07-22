// getting nth fibonacci number in o(logn) time
// Matrix exponentiation is used
#include<bits/stdc++.h>
using namespace std;


void multiply(int A[2][2],int M[2][2])
{
	int fvalue = A[0][0]*M[0][0] + A[0][1]*M[1][0];
	int svalue = A[0][0]*M[0][1] + A[0][1]*M[1][1];
	int tvalue = A[1][0]*M[0][0] + A[1][1]*M[1][0];
	int lvalue = A[1][0]*M[0][1] + A[1][1]*M[1][1];
	A[0][0]=fvalue;
	A[0][1]=svalue;
	A[1][0]=tvalue;
	A[1][1]=lvalue;
	return ;
}
void power(int A[2][2],int n)
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
		int M[2][2]={{1,1},{1,0}};
		multiply(A,A);
		multiply(A,M);
	}
	return ;

}

int fib(int n)
{
	if(n==0 || n==1)
	{
		return n;
	}
	int A[2][2]={{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}
int main()
{
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}