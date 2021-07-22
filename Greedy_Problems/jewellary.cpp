#include<bits/stdc++.h>
using namespace std;


bool compare(const pair<int,int> a,const pair<int,int> b)
{
	// if profit not equal
	if(a.second!=b.second)
	{
		return a.second > b.second;
	}
	// if profits are equal
	return a.first < b.first;
}


int main()
{
	int n,k;
	cin >> n >> k;
	pair<int,int>* input = new pair<int,int>[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i].first >> input[i].second;
	}
	// sorting in decreasing order on the basis of profit
	sort(input,input+n,compare);
	multiset<int> m;
	long long total=0;
	for(int i=0;i<k;i++)
	{
		int x;
		cin >> x;
		m.insert(x);
	}
	for(int i=0;i<n;i++)
	{
		if(m.empty())
		{
			break;
		}
		// we are finding bag which has capacity just greater then the current weight of  piece element
		else if(m.lower_bound(input[i].first)!=m.end())// bag found
		{
			// we are including
			total+=input[i].second;
			m.erase(m.lower_bound(input[i].first));// we are removing that bag
		}
		// else we are not including and not considering so nothing....
	}
	cout << total << endl;// total is the max profit we got by including some jewels
	delete[] input;
	return 0;

}