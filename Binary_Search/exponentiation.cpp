#include<bits/stdc++.h>
using namespace std;

// O(log(b))
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
	value=value*value;
	if(b%2!=0)//odd
	{
		value = value*a;
	}
	return value;


}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << power(a,b) << endl;
	return 0;
}