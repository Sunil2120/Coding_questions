#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,unordered_map<int,unordered_set<int>>& edges)
{
	int count = 0;
	do
	{
		int check = 0;
		for(int i=0;i<arr.size()-1;i++)
		{
			if(edges[arr[i]].find(arr[i+1])==edges[arr[i]].end())//not present
			{
				check = 1;
				break;
			}
		}
		if(check==0)
		{
			count+=1;
		}

	}while(next_permutation(arr.begin(),arr.end()));
	return count;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> arr;
	unordered_map<int,unordered_set<int>> edges;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		edges[f].insert(s);
		edges[s].insert(f);
	}
	cout << solve(arr,edges) << endl;
	return 0;
}