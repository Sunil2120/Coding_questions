#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	return a.first < b.first;
}

int solve(vector<int>& stocks,int n,int k)
{
	vector<pair<int,int>> temp;
	for(int i=0;i<n;i++)
	{
		temp.push_back(make_pair(stocks[i],i+1));
	}
	sort(temp.begin(),temp.end(),compare);
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(k<=0)
		{
			break;
		}
		int temp2 = k/(temp[i].first);
		if(temp2 >= temp[i].second)
		{
			count+=temp[i].second;
			k-=(temp[i].first*temp[i].second);
		}
		else
		{
			count+=temp2;
			k-=(temp[i].first*temp2);
		}
	}
	return count;

}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> stocks(n);
	for(int i=0;i<n;i++)
	{
		cin >> stocks[i];
	}
	cout << solve(stocks,n,k) << endl;
	return 0;
}