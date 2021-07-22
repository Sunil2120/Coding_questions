#include<bits/stdc++.h>
using namespace std;

int solve(int** cost,int m,int n)
{
	vector<bool> visited(n,false);
	int total = 0;
	for(int i=0;i<m;i++)
	{
		 int min_value = INT_MAX;
		 int min_i = -1;
		for(int j=0;j<n;j++)
		{
			if(cost[i][j] < min_value)
			{
				min_value = cost[i][j];
				min_i = j;
			}
		}
		total+=min_value;
		visited[min_i]=true;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			int min_value = INT_MAX;
			for(int j=0;j<m;j++)
			{
				if(cost[j][i] < min_value)
				{
					min_value = cost[j][i];
				}
			}
			total+=min_value;
			visited[i]=true;
		}
	}
	return total;
}

int main()
{
	int m,n;
	cin >> m >> n;
	int** cost = new int*[m];
	for(int i=0;i<m;i++)
	{
		cost[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> cost[i][j];
		}
	}
	cout << solve(cost,m,n) << endl;
}