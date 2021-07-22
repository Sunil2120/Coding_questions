// we should find gcd of (a,b)
// a can be massive 0 <= a <= 10 power of 250
// for b 0<= b <=10 power of some 4
// wkt gcd(a,b) = gcd(b,a%b) our main objective is to make a%b to be within integer range
#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);

}


// here we are making a%b to be within range
int solve(string a,int b)
{
	int prev = 0;
	int res = 0;
	for(int i=0;i<a.length();i++)
	{
		int digit = a[i] - '0';
		res = (((res%b)*(10%b))%b + (digit%b))%b;
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a;
		cin >> a;
		int b;
		cin >> b;
		int value =  solve(a,b) ;// a%b within int range
		cout << gcd(b,value);
	}
	
	return 0;
}