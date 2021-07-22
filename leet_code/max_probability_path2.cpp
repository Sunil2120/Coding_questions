
// max probability path 2
#include<bits/stdc++.h>
using namespace std;

// dijstra using priority queue takes less time than the normal one

int main()
{
	int n;
	cin >> n;
	int e;
	cin >> e;
	map<int,vector< pair<int,double> > > adj;
	for(int i=0;i<e;i++)
	{
		int f,s;
		double val;
		cin >> f >> s >> val;
		adj[f].push_back(make_pair(s,val));
		adj[s].push_back(make_pair(f,val));
	}
	int source,dest;
	cin >> source >> dest;
	bool* visited = new bool[n]();
	double* dis = new double[n];// pro from source to i node
	for(int i=0;i<n;i++)
	{
		dis[i]=0;
	}
	// probablity from source to source is 1;
	dis[source]=1;
	priority_queue< pair<double,int> > pq;
	pq.push(make_pair(1,source));
	while(!pq.empty())
	{
		auto temp = pq.top();
		double val = temp.first;
		int index = temp.second;
		pq.pop();
		if(visited[index]==true)
		{
			continue;
		}
		visited[index]=true;
		dis[index]=val;
		// explore it's neighbour
		vector< pair<int,double> > suni = adj[index];
		for(int i=0;i<suni.size();i++)
		{
			int next = suni[i].first;
			double val = suni[i].second;
			if(dis[next] < (val*dis[index]))
			{
				pq.push(make_pair(val*dis[index],next));
			}
		}
	}
	cout << fixed << setprecision(4) << dis[dest] << endl;
	delete[] visited;
	delete[] dis;
	cout << endl;
}