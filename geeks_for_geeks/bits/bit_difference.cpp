#include<bits/stdc++.h>
using namespace std;

int count_bits(int  n)
{
	int count = 0;
	while(n!=0)
	{
		int rmsb = n&-n;
		n = n - (rmsb);
		count+=1;
	}
	return count;
}

int main()
{
	int x,y;
	cin >> x >> y;
	int output = x^y;
	cout << count_bits(output) << endl;
	return 0;
}