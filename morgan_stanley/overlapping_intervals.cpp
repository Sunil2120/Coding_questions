#include<bits/stdc++.h>
using namespace std;




void solve(vector<pair<int,int>>& input,int n)
{
	if(n==0)
	{
		return ;
	}
	vector<pair<int,int>> output;
	sort(input.begin(),input.end());
	output.push_back(input[0]);
	for(int i=1;i<n;i++)
	{
		pair<int,int> cur = output.back();
		output.pop_back();
		if(input[i].first >= cur.first && input[i].first <= cur.second)
		{
			cur.first = min(input[i].first,cur.first);
			cur.second = max(input[i].second,cur.second);
			output.push_back(cur);
		}
		else
		{
			output.push_back(cur);
			output.push_back(input[i]);
		}
	}
	for(int i=0;i<output.size();i++)
	{
		cout << output[i].first << " " << output[i].second << endl;
	}
	return ;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<pair<int,int>> input;
		for(int i=0;i<n;i++)
		{
			int f,s;
			cin >> f >> s;
			input.push_back(make_pair(f,s));
		}
		solve(input,n);
	}
	return 0;
}