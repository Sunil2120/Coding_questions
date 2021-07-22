#include<bits/stdc++.h>
using namespace std;


int solve(int x,int y)
{
	if(x+y <= 11)
	{
		return x+y;
	}
	else
	{
		int result = x + y - 12;
		return result;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x,y;
		cin >> x >> y;
		cout << solve(x,y) << endl;
	}
}