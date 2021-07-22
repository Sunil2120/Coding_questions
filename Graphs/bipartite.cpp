// it's same for both directed and undirected graph
#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int>* edges,int v)
{
	if(v==0)
	{
		return true;
	}
	set<int> s[2];
	queue<int> Q;
	// we will start from 0;
	Q.push(0);
	// we will insert 0 in first set
	s[0].insert(0);
	while(Q.size()!=0)
	{
		int cur = Q.front();
		Q.pop();
		int cur_set = s[0].count(cur) > 0 ? 0 : 1;
		for(int i=0;i<edges[cur].size();i++)
		{	
			int adj = edges[cur][i];
			// if adj is not in both the sets
			if(s[0].count(adj)==0 && s[1].count(adj)==0)
			{
				s[cur_set^1].insert(adj);
				Q.push(adj);
			}
			// if it is present in same set
			else if(s[cur_set].count(adj) > 0)
			{
				return false;
			}
			// else it is present is opposite set we will continue
		}
			
	}
	return true;

}


int main()
{
	while(1)
	{
		int v,e;
		cin >> v >> e;
		if(v==0)
		{
			break;
		}
		vector<int>* edges = new vector<int>[v];
		for(int i=0;i<e;i++)
		{
			int x,y;
			cin >> x >> y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		bool ans = solve(edges,v);
		if(ans)
		{
			cout << "BICOLORABLE" << endl;
		}
		else
		{
			cout << "NOT BICOLORABLE" << endl;
		}

		delete[] edges;
	
	}
}