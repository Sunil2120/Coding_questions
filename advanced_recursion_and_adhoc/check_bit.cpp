#include<bits/stdc++.h>
using namespace std;


int check(int n)
{
	// for(int i=0;i<8;i++)
	// {
	// 	if((n & (1 << i)) != 0)
	// 	{
	// 		return i;
	// 	}
	// }
	// return 8;
	int i=0;
	if(n==0)
	{
		return -1;
	}

	while( (n & (1 << i)) == 0 )
	{
		i++;
	}
	int n1 =  n & (~(1 << i));
	return n1;
}

int clear(int n,int i)
{
	if(n==0)
	{
		return 0;
	}
	return n & ( (1 << i)-1);
}



int main()
{
	int n;
	cin >> n;
	cout << check(n) << endl;
	cout << clear(n,3) << endl;
	return 0;
}