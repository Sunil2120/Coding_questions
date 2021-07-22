#include<bits/stdc++.h>
using namespace std;

//O(logn) and auxillary space O(1)
int solve(int n)
{
	int count = 0;
	while(n!=0)
	{
		n=n&(n-1);
		count+=1;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}