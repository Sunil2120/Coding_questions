#include<bits/stdc++.h>

using namespace std;


int solve(pair<int,int>* arr,int n,pair<int,int> start,pair<int,int> end)
{
	if(n==0)
	{
		return abs(end.first - start.first)+abs(end.second - start.second);
	}
	int min_value = INT_MAX;
	do
	{
		int sum = 0;
		for(int i=0;i<n-1;i++)
		{
			sum+=abs(arr[i+1].first - arr[i].first)+abs(arr[i+1].second - arr[i].second);
		}
		sum += abs(arr[0].first - start.first)+abs(arr[0].second - start.second);
		sum+= abs(end.first - arr[n-1].first)+abs(end.second - arr[n-1].second);
		min_value = min(min_value,sum);
	}while(next_permutation(arr,arr+n));
	return min_value;
}

int main()
{
	int n;
	cin >> n;
	pair<int,int> start;
	cin >> start.first >> start.second ;
	pair<int,int> end;
	cin >> end.first >> end.second ;
	pair<int,int>* arr = new pair<int,int>[n];
	for(int i=0;i<n;i++)
	{
		int f,s;
		cin >> f >> s;
		arr[i]=make_pair(f,s);
	}
	cout << solve(arr,n,start,end) << endl;
	return 0;
}