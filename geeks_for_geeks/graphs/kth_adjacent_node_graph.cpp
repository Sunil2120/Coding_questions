#include<bits/stdc++.h>
using namespace std;


bool compare(int a,int b)
{
	return a > b;
}
void solve(map<int,vector<int>>& adj,int n,int* weights,int  k,map<int,int>& w)
{
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<adj[i].size();j++)
		{
			int next = adj[i][j];
			temp.push_back(weights[next]);
		}
		sort(temp.begin(),temp.end(),compare);
		if(k-1 >= temp.size() || k-1 < 0 || temp.size()==0)
		{
			cout << -1 << " ";
		}
		else
		{
			
			cout << w[temp[k-1]] << " ";
		}
	}
	cout << endl;
	return ;

}

int main()
{
	int n,k;
	cin >> n >> k;
	int m;
	cin >> m;
	map<int,vector<int>> adj;
	map<int,int> w;
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);// undirected graph
	}
	int* weights = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> weights[i];
		w[weights[i]]=i;
	}
	solve(adj,n,weights,k,w);
	return 0;
}