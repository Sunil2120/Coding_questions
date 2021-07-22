#include<bits/stdc++.h>
using namespace std;



bool solve(vector<pair<int,int>>& locations,vector<pair<int,int>>& targets,int m,int n,int d)
{
	for(int i=0;i<n;i++)
	{
		int count = 0;
		for(int j=0;j<m;j++)
		{
			int value= abs(locations[i].first - targets[j].first)+abs(locations[i].second - locations[j].second);
			if(value==d)
			{
				count+=1;
			}
		}
		if(m%2 == 0)
		{
			if(count > m/2)
			{
				return true;
			}
		}
		else
		{
			if(count > ((m/2)+1))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int n,m,d;
	cin >> n >> m >> d;
	vector<pair<int,int>> locations(n);
	vector<pair<int,int>> targets(n);
	for(int i=0;i<n;i++)
	{
		int f,s;
		cin >> f >> s;
		locations[i]=make_pair(f,s);
	}
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f>> s;
		targets[i]=make_pair(f,s);
	}
	cout << solve(locations,targets,m,n,d) << endl;
	return 0;
}