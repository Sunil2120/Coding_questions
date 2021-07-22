#include<bits/stdc++.h>
using namespace std;


int getLargestpowerof2(int n)
{
	int x=0;
	//(1<<x)==(2**x)
	while( (1<<x) <= n)
	{
		x++;
	}
	return x-1;

}

int solve(int n)
{
	if(n==0)
	{
		return 0;
	}
	
	int x = getLargestpowerof2(n);
	
	int result = ((1<<(x-1))*x)+(n-(1<<x)+1)+solve(n-(1<<x));
	return result;
}
int main()
{

	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}