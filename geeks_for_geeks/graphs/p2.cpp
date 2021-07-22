#include<bits/stdc++.h>
using namespace std;

int getmin(vector<int>& net_worth,int n)
{
	int min_value = net_worth[0];
	int min_i = 0;
	for(int i=1;i<n;i++)
	{
		if(net_worth[i] < min_value)
		{
			min_value = net_worth[i];
			min_i = i;
		}
	}
	return min_i;
}

int getmax(vector<int>& net_worth,int n)
{
	int min_value = net_worth[0];
	int min_i = 0;
	for(int i=1;i<n;i++)
	{
		if(net_worth[i] > min_value)
		{
			min_value = net_worth[i];
			min_i = i;
		}
	}
	return min_i;
}


void solve(vector<int>& net_worth,int n,int** adj)
{

	//get max_deb and max_cre
	int max_deb = getmin(net_worth,n);
	int max_cre = getmax(net_worth,n);
	if(net_worth[max_deb]==0 && net_worth[max_cre]==0)
	{
		return ;
	}
	int min_value = min(abs(net_worth[max_deb]),abs(net_worth[max_cre]));
	net_worth[max_cre]-=min_value;
	net_worth[max_deb]+=min_value;
	cout << max_deb << " " << max_cre << " " << min_value << endl;
	return solve(net_worth,n,adj);

}
int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	int** adj = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			adj[i][j]=INT_MAX;
		}
	}
	vector<int> net_worth(n,0);
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u][v]=w;
		//u--->v
		net_worth[v]+=w;
		net_worth[u]-=w;
	}
	solve(net_worth,n,adj);
	return 0;
}