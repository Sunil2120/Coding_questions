// complement a given graph(draw edges to pair of vertices which don't have edge and remove edges of those pairs who have edge  )
// check whether the complement graph is bipartite or not
#include<bits/stdc++.h>
using namespace std;


bool isbipartite(int** adjC,int n)
{
	set<int> s[2];
	queue<int> Q;
	s[0].insert(0);
	Q.push(0);
	while(Q.size()!=0)
	{
		int i = Q.front();
		Q.pop();
		int cur = s[0].find(i)!=s[0].end()?0:1;
		// check it's neighbours
		for(int j=0;j<n;j++)
		{
			if(adjC[i][j]==1)
			{
				// if not present in both sets
				if(s[0].find(j)==s[0].end() && s[1].find(j)==s[1].end())
				{
					s[cur^1].insert(j);
					Q.push(j);
					continue;
				}
				// present in same set
				if(s[cur].find(j)!=s[cur].end())
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	int n,e;
	cin >> n >> e;
	int** adj = new int*[n];
	int** adjC = new int*[n];
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n]();
		adjC[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f][s]=1;
		adj[s][f]=1;// undirected graph
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			adjC[i][j] = adj[i][j]^1;
			if(i==j)
			{
				adjC[i][j]=0;
			}
		}
	}
	cout << isbipartite(adjC,n) << endl;
	return 0;

}