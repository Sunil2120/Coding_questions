#include<bits/stdc++.h>
using namespace std;

struct suni
{
	bool operator()(pair<int,int> const& a,pair<int,int> const& b)
	{
		return a.second > b.second;

	}

};



void solve(int** edges,int V,int E,map<int,vector<int>> hash)
{
	bool* visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	int* parent = new int[V];
	for(int i=0;i<V;i++)
	{
		parent[i]=-1;
	}
	int* weight = new int[V];
	for(int i=0;i<V;i++)
	{
		weight[i]=INT_MAX;
	}
	int count = 0;
	weight[0]=0;
	// priority queue
	priority_queue< pair<int,int> , vector< pair<int,int> >, suni > pq;
	pq.push(make_pair(0,weight[0]));
	// while(!pq.empty() && count < V)
	for(int i=0;i<V-1;i++)
	{
		pair<int,int> temp1 = pq.top();
		//cout << temp1.first << " " << temp1.second << endl;
		pq.pop();
		int minvertex = temp1.first;
		if(visited[minvertex]==true)
		{
			continue;
		}
		vector<int> temp = hash[minvertex];
		visited[minvertex]=true;
		for(int j=0;j<temp.size();j++)
		{
			if(temp[j]==minvertex)
			{
				continue;
			}
			if(visited[temp[j]]==true)
			{
				continue;
			}
			if(weight[temp[j]] > edges[minvertex][temp[j]])
			{
				//cout << "hi" << " " << minvertex << " " << temp[j] << endl;
				weight[temp[j]]=edges[minvertex][temp[j]];
				parent[temp[j]]=minvertex;
				pq.push(make_pair(temp[j],weight[temp[j]]));
			}
		}

	}
	for(int i=1;i<V;i++)
	{
		cout << parent[i] << " " << i << " " << weight[i] << endl;
	}
	return ;

}



int main()
{
	int V,E;
	cin >> V >> E;
	map<int,vector<int>> hash;
	int** edges = new int*[V];
	for(int i=0;i<V;i++)
	{
		edges[i]=new int[V]();
	}
	for(int i=0;i<E;i++)
	{
		int first,second,w;
		cin >> first >> second >> w;
		hash[first].push_back(second);
		hash[second].push_back(first);
		edges[first][second]=w;
		edges[second][first]=w;
	}
	solve(edges,V,E,hash);
	return 0;
}