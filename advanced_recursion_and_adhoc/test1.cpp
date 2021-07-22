#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define MAX2 10000


void multiply(int A[2][2],int M[2][2])
{
	int fvalue = A[0][0]*M[0][0]%3 + A[0][1]*M[1][0]%3;
	int svalue = A[0][0]*M[0][1]%3 + A[0][1]*M[1][1]%3;
	int tvalue = A[1][0]*M[0][0]%3 + A[1][1]*M[1][0]%3;
	int lvalue = A[1][0]*M[0][1] %3+ A[1][1]*M[1][1]%3;
	A[0][0]=fvalue%3;
	A[0][1]=svalue%3;
	A[1][0]=tvalue%3;
	A[1][1]=lvalue%3;
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


void solve(long long* arr,long long* arr1,long long* sum1,long long* sum2)
{
	//cout << 1 << endl;
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<=MAX;i++)
	{
		arr[i]=arr[i-1] + arr[i-2];
		arr[i]=arr[i]%3;
	}
	//cout << 2 << endl;
	//cout << arr[MAX-1] << " " << arr[MAX] << endl;
	arr1[0]=arr[MAX-1]+arr[MAX];
	arr1[1]= arr1[0] + arr[MAX];
	for(int i=2;i<=MAX2;i++)
	{
		//cout << i << endl;
		arr1[i]=arr[i-1] + arr[i-2];
		arr1[i]=arr1[i]%3;
	 }
	//cout << 3 << endl;
	sum1[0]=0;
	sum1[1]=1;
	for(int i=2;i<=MAX;i++)
	{
		long long temp = arr[i]%3;
		sum1[i]=sum1[i-1] + temp;
	}
	//cout << 4 << endl;
	sum2[0] = sum1[MAX]+arr1[0]%3;
	sum2[1]= sum2[0] + arr1[1]%3;
	for(int i=2;i<=MAX2;i++)
	 {
		long long temp = arr1[i]%3;
	 	sum2[i]=sum2[i-1] + temp;
	 }
	 //cout << 5 << endl;
	return ;

}
int main()
{
	int t;
	cin >> t;
	long long* arr = new long long[MAX+1];
	long long* arr1 = new long long[MAX+1];
	long long* sum1 = new long long[MAX+1];
	long long* sum2 = new long long[MAX+1];
	solve(arr,arr1,sum1,sum2);
	while(t--)
	{
		int n;
		cin >> n;
		if(n <= MAX)
		{
			cout << sum1[n] << endl;
		}
		else
		{
			cout << sum2[n] << endl;
		}
	}
	delete[] arr;
	delete[] arr1;
	delete[] sum1;
	delete[] sum2;
	return 0;
}