#include<bits/stdc++.h>
using namespace std;



void solve2(vector<int>& top,int target,int& max_value,int cur,int index)
{
	if(cur > target)
	{
		return ;
	}
	if(index==top.size())
	{
		if(cur > max_value)
		{
			max_value = cur;
		}
		return ;
	}
	solve2(top,target,max_value,cur,index+1);
	solve2(top,target,max_value,cur+top[index],index+1);
	return ;

}
int solve(vector<int>& base,vector<int>& top,int n,int target)
{
	int max_value2 = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(base[i] > target)
		{
			continue;
		}
		int max_value = INT_MIN;

		solve2(top,target-base[i],max_value,0,0);
		//cout <<max_value << endl;
		max_value2 = max(max_value2,max_value+base[i]);
	}
	return max_value2;
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> base(n);
	vector<int> top(2*m);
	for(int i=0;i<n;i++)
	{
		cin >> base[i];
	}
	for(int i=0;i<m;i++)
	{
		int a;
		cin >> a;
		top.push_back(a);
		top.push_back(a);
	}
	int target;
	cin >> target;
	cout << solve(base,top,n,target) << endl;
}