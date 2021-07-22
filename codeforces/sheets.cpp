#include<bits/stdc++.h>
using namespace std;


bool solve(int w,int h,int level,int k)
{
	if(w<=0 || h<=0)
	{
		return false;
	}
	if(pow(2,level) >= k)
	{
		return true;
	}
	bool first = false;
	bool second = false;
	if((w%2)==0)
	{
		first = solve(w/2,h,level+1,k);
	}
	if((h%2)==0)
	{
		second = solve(w,h/2,level+1,k);
	}
	if(first || second)
	{
		return true;
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int w,h,k;
		cin >> w >> h >> k;
		bool result = solve(w,h,0,k);
		if(result)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}