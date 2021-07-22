#include<bits/stdc++.h>
using namespace std;



void dfs(vector<int>* edges,int start,int parent,int v,bool* visited,int* in,int* low,int timer)
{
	visited[start]=true;
	in[start]=low[start]=timer;
	timer+=1;
	for(int i=0;i<edges[start].size();i++)
	{
		int adj = edges[start][i];
		if(adj==parent)
		{
			continue;
		}
		if(visited[adj]==true)
		{
			low[start]=min(low[start],in[adj]);
		}
		if(visited[adj]==false)
		{
			dfs(edges,adj,start,v,visited,in,low,timer);
			if(low[adj] > in[start])// adj has no direct edge with the ancestors of start it's a bridge
			{
				cout << start+1 << " " << adj+1 << " " << "is a bridge" << endl;
			}
			low[start]=min(low[start],low[adj]);// 
		}
	}

}



void solve(vector<int>* edges,int v,int e)
{
	bool* visited = new bool[v];
	int* in = new int[v];// arrival time
	int* low = new int[v];// lowest ancestor with which i has a direct edge
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		in[i]=-1;
		low[i]=-1;
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			dfs(edges,i,-1,v,visited,in,low,0);
		}
	}
	delete[] visited;
	delete[] in;
	delete[] low;
	return ;
}
int main()
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
	solve(edges,v,e);
}