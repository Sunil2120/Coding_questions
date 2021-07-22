#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int>* edges,int start,bool* visited,vector<int> &temp)
{
	visited[start]=true;
	temp.push_back(start);
	for(int i=0;i<edges[start].size();i++)
	{
		int adj = edges[start][i];
		if(visited[adj]==false)
		{
			dfs(edges,adj,visited,temp);
		}
	}
	return ;
}


long long solve(vector<int>* edges,long long* arr,int v)
{
	bool* visited = new bool[v];
	vector<vector<int>> output;
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{	
			vector<int> temp;
			dfs(edges,i,visited,temp);
			output.push_back(temp);
		}
	}

	long long max_ = INT_MIN;
	for(int i=0;i<output.size();i++)
	{
		long long count = 0;
		for(int j=0;j<output[i].size();j++)
		{
			int adj = output[i][j];
			count+=arr[adj];
		}
		if(count > max_)
		{
			max_ = count;
		}
	}
	delete[] visited;
	return max_;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int v,e;
		cin >> v >> e;
		vector<int>* edges = new vector<int>[v];
		for(int i=0;i<e;i++)
		{
			int x,y;
			cin >> x >> y;
			edges[x-1].push_back(y-1);
			edges[y-1].push_back(x-1);
		}
		long long* arr = new long long[v];
		for(int i=0;i<v;i++)
		{
			cin >> arr[i];
		}
		cout << solve(edges,arr,v) << endl;
		delete[] edges;
		delete[] arr;
	}
	return 0;
}