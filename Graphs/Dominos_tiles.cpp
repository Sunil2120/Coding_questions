#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int>* edges,vector<int>* edgesT,int start,bool* visited,int& count)
{
	if(edgesT[start].size()==0)// no incoming
	{
		count+=1;
	}
	visited[start]=true;
	for(int i=0;i<edges[start].size();i++)
	{
		int adj = edges[start][i];
		if(visited[adj]==false)
		{
			dfs(edges,edgesT,adj,visited,count);
		}
	}
	// finished.push(start);
	return ;
}

// void dfs2(vector<int>* edges,int start,bool* visited)
// {
// 	visited[start]=true;
// 	for(int i=0;i<edges[start].size();i++)
// 	{
// 		int adj = edges[start][i];
// 		if(!visited[adj])
// 		{
// 			dfs2(edges,adj,visited);
// 		}
// 	}
// 	return ;
// }


int solve(vector<int>* edges,vector<int>* edgesT,int n)
{
	bool* visited = new bool[n];
	int count = 0;
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	// stack<int> finished;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(edges,edgesT,i,visited,count);

		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	visited[i]=false;
	// }
	// while(finished.size()!=0)
	// {
	// 	int cur = finished.top();
	// 	finished.pop();
	// 	if(visited[cur]==true)
	// 	{
	// 		continue;
	// 	}
	// 	count+=1;
	// 	dfs2(edgesT,cur,visited);
	// }
	delete[] visited;
	return count;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector<int>* edges = new vector<int>[n];// outdegree
		vector<int>* edgesT = new vector<int>[n];// indegree
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			edges[x-1].push_back(y-1);
			edgesT[y-1].push_back(x-1);
		}
		cout << solve(edges,edgesT,n) << endl;
		delete[] edges;
		delete[] edgesT;
	}
	return 0;
}