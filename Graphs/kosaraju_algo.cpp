// kosaraju's algorithm is used to find the connected components in directed graphs
#include<bits/stdc++.h>
using namespace std;



void dfs(vector<int>* edges,int start,set<int>& visited,stack<int>& finished,int v)
{
	visited.insert(start);

	for(int i=0;i<edges[start].size();i++)
	{
		if(visited.count(edges[start][i])==0)
		{
			dfs(edges,edges[start][i],visited,finished,v);
		}
		
	}
	finished.push(start);
	return ;
}

void dfs2(vector<int>* edges,int start,set<int>& visited,vector<int>& comp,int v)
{
	visited.insert(start);
	comp.push_back(start+1);
	for(int i=0;i<edges[start].size();i++)
	{
		if(visited.count(edges[start][i])==0)
		{
			dfs2(edges,edges[start][i],visited,comp,v);
		}
		
	}
	return ;
}


void solve(vector<int>* edges,vector<int>* edgesT,int v)
{
	set<int> visited;
	stack<int> finished;
	vector< vector<int> > output;
	for(int i=0;i<v;i++)
	{
		if(visited.count(i)==0)// false
		{
			dfs(edges,i,visited,finished,v);
		}
	}
	visited.clear();
	while(finished.size()!=0)
	{
		int cur = finished.top();
		finished.pop();
		//cout << cur << endl;
		if(visited.count(cur)!=0)// already visited
		{
			continue;
		}
		vector<int> temp;
		dfs2(edgesT,cur,visited,temp,v);
		output.push_back(temp);
	
	}

	for(int i=0;i<output.size();i++)
	{
		for(int j=0;j<output[i].size();j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	//set< set<int>* >* output = getcomp(edges,V,p);
	// set< set<int>* > :: iterator it=(output)->begin();
	// while(it!=(output)->end())
	// {
	// 	set<int>* cur = *it;
	// 	set<int> :: iterator jt = (cur)->begin();
	// 	while(jt!=(cur)->end())
	// 	{
	// 		cout << *jt << " ";
	// 		jt++;
	// 	}
	// 	cout << endl;
	// 	it++;
	// }
	return ;
}



int main()
{
	int v,e;
	cin >> v >> e;
	vector<int>* edges = new vector<int>[v];
	vector<int>* edgesT = new vector<int>[v];
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin >> x >> y;
		edges[x-1].push_back(y-1);
		edgesT[y-1].push_back(x-1);
	}
	solve(edges,edgesT,v);
	return 0;
}