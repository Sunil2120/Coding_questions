#include<bits/stdc++.h>
using namespace std;

int solve2(int h,int a,int cur,map<pair<int,int>,int>& hash)
{
	if(h<=0 || a<=0)
	{
		return 0;
	}
	if(hash[make_pair(h,a)]!=0)
	{
		return hash[make_pair(h,a)];
	}
	if(cur==1)
	{
		hash[make_pair(h,a)] = max(solve2(h-5,a-10,2,hash),solve2(h-20,a+5,3,hash))+1;
	}
	else
	{
		hash[make_pair(h,a)] = solve2(h+3,a+2,1,hash)+1;
	}
	return hash[make_pair(h,a)];


}

int solve(int h,int a)
{
	//1 air
	//2 water
	//3 fire
	map<pair<int,int>,int> hash;
	return max(solve2(h+3,a+2,1,hash),max(solve2(h-5,a-10,2,hash),solve2(h-20,a+5,3,hash)));
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int h,a;
		cin >> h >> a;
		cout <<solve(h,a) << endl;
	}
	return 0;
}