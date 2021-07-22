// travelling sales man problem
// problem is to travel all given cities exactly once and return back to same city where started
// TSP is same as Hamiltonian cycle but cycle which gives the min cost is the ans
#include<bits/stdc++.h>
using namespace std;


int solve(int** adj,int n,int e)
{
	// let us consider 0 as start vertex
	vector<int> vertices;
	int s = 0;
	for(int i=0;i<n;i++)
	{
		if(i!=s)
		{
			// we will push all vertices except the source vertex
			vertices.push_back(i);
		}
	}
	int min_cost = INT_MAX;
	vector<int> min_path(n+1,0);
	// we need for atleast once so do while
	do
	{
		int cost = 0;
		for(int i=0;i<vertices.size()-1;i++)
		{
			cost+=adj[vertices[i]][vertices[i+1]];
		}
		cost = cost + adj[s][vertices[0]] + adj[vertices[vertices.size()-1]][s];
		if(cost < min_cost)
		{
			min_path[0]=s;
			min_path[n]=s;
			int j=1;
			for(int i=0;i<vertices.size();i++)
			{
				min_path[j]=vertices[i];
				j+=1;
			}
			min_cost = cost;
		}
	}while(next_permutation(vertices.begin(),vertices.end()));

	for(int i=0;i<=n;i++)
	{
		cout << min_path[i] << " ";
	}
	cout << endl;
	return min_cost;
}

int main()
{
	int n,e;
	cin >> n >> e;
	int** adj=new int*[n];
	for(int i=0;i<n;i++)
	{
		// complete graph
		adj[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int f,s,v;
		cin >> f >> s >> v;
		adj[f][s]=v;
		adj[s][f]=v;
	}
	cout << solve(adj,n,e) << endl;
	return 0;
}