#include<bits/stdc++.h>
using namespace std;

int getdigits(int n)
{
	int count = 0;
	while(n!=0)
	{
		count+=1;
		n=n/10;
	}
	return count;
}

int power(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a;
	}
	int value = power(a,b/2);
	if(b%2 == 0)
	{
		return value*value;
	}
	return value*value*a;
}

int main()
{
	int n1;
	cin >> n1;
	int sum = 0;
	int n = n1;
	int no_digits = getdigits(n);
	while(n!=0)
	{
		int rem = n%10;
		sum+=power(rem,no_digits);
		n = n/10;
	}
	if(sum == n1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;

}