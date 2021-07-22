#include<bits/stdc++.h>
using namespace std;

void dfs(map<int,vector<int>> & hash , int start,int cost,bool* visited,double cur,double& value)
{
	visited[start]=true;
	int count = 0;
	for(int i=0;i<hash[start].size();i++)
	{
		if(visited[hash[start][i]]==false)
		{
			count+=1;// connected neighbours not visited
		}
	}
	if(count==0)
	{
		return ;
	}
	double p = cur/count;

	for(int i=0;i<hash[start].size();i++)
	{
		if(visited[hash[start][i]]==false)
		{
			value+= p*cost;
			dfs(hash,hash[start][i],cost,visited,p,value);
		}
	}

}

double solve(map<int,vector<int>> & hash,int cost,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	double value=0;
	dfs(hash,0,cost,visited,1,value);
	delete[] visited;
	return  value;

}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,cost;
		cin >> n >> cost;
		map<int,vector<int> > hash;
		for(int i=0;i<n-1;i++)
		{
			int f,s;
			cin >> f >> s;
			hash[f-1].push_back(s-1);
			hash[s-1].push_back(f-1);
		}
	
		cout << fixed << setprecision(4) << solve(hash,cost,n) << endl;

	}
}