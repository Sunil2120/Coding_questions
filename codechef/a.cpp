#include<bits/stdc++.h>
using namespace std;


void func(int a,int b)
{
	cout << ++a << " " << ++b ;
}
int main()
{
	int x;
	x=10;
	func(++x,x++);
	func(x++,++x);
	cout << x << endl;
	return 0;
}