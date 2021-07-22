#include<bits/stdc++.h>
using namespace std;


void solve(int n)
{
	int* fib = new int[n];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(int i=n-1;i>=0;i--)
	{
		cout << fib[i] << " ";
	}
	cout << endl;
	return ;
}
int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}