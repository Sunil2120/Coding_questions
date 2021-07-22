#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}
int solve(vector<vector<pair<int,int>>>& platforms,int n)
{
	for(int i=0;i<n;i++)
	{
		sort(platforms[i].begin(),platforms[i].end(),compare);
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(platforms[i].size() > 0)
		{
			int check = platforms[i][0].second;
			count+=1;
			for(int j=1;j<platforms[i].size();j++)
			{
				if(platforms[i][j].first >= check)
				{
					count+=1;
					check = platforms[i][j].second;
				}
			}
		}
	}
	return count;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> platforms(n);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		platforms[c-1].push_back(make_pair(a,b));
	}
	cout << solve(platforms,n) << endl;
	return 0;
}