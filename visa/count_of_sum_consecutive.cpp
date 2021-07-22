#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
	int count = 0;
	for(int l=1;(l*(l+1))/2 < n ;l++)
	{
		float a = l*(l+1)*0.5;
		a = n-a;
		a=a/(l+1);
		if(a - (int)a == 0.0)
		{
			count+=1;
		}
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