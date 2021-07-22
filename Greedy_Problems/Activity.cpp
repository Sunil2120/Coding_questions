#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}

int max_activity(int n,vector<pair<int,int>> input)
{
	if(n==0)
	{
		return 0;
	}
	sort(input.begin(),input.end(),compare);
	int count =1;
	int j = input[0].second
	for(int i=1;i<n;i++)
	{
		if(input[i].first >= j)
		{
			count+=1;
			j=input[i].second;
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector< pair<int,int> > input(n);
	for(int i=0;i<n;i++)
	{
		int first,second;
		cin >> first >> second;
		input[i]=make_pair(first,second);
	}
	cout << max_activity(n,input) << endl;
	return 0;
}