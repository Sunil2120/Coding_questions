#include<bits/stdc++.h>
using namespace std;


int solve(int n)
{
	int end = (2*(n-1))+1;
	int start = 1;
	int value = (start + end)/2;
	int total = 0;
	for(int i=0;i<(n/2);i++)
	{
		int cur = (2*i)+1;
		total+=(value-cur);
	}
	return total;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
}