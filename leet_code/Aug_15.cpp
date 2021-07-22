// non overlapping intervals
#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int> a , const pair<int,int> b)
{
	return a.second < b.second;
}

int solve(vector< pair<int,int> >& input,int n)
{
	if(n==0)
	{
		return 0;
	}
	sort(input.begin(),input.end(),compare);
	int count = 0;
	int c = 0;
	int sec = input[0].second;
	for(int i=1;i<input.size();i++)
	{
		if(input[i].first < sec)
		{
			count+=1;
		}
		else
		{
			sec = input[i].second;
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector< pair<int,int> > input;
	for(int i=0;i<n;i++)
	{
		int f,s;
		cin >> f >> s;
		input.push_back(make_pair(f,s));
	}
	cout << solve(input,n) << endl;
}