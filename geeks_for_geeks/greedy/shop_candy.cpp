#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& candies,int n,int k)
{
	if(n==0)
	{
		return ;
	}
	sort(candies.begin(),candies.end());
	// minimum amount
	int i=0;
	int j=n-1;
	int min_cost = 0;
	while(i<=j)
	{
		min_cost+=candies[i];
		j-=k;
		i+=1;	
	}
	i=0;
	j=n-1;
	int max_cost = 0;
	while(i<=j)
	{
		max_cost+=candies[j];
		i+=k;
		j-=1;
	}
	cout << min_cost << " " << max_cost << endl;
	return ;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> candies(n);
		for(int i=0;i<n;i++)
		{
			cin >> candies[i];
		}
		solve(candies,n,k);
	}
	
	return 0;
}