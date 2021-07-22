// bottom of the graph
// if A has an outgoing edge to B then if B has an outgoing edge to A then A,B are known as sinks
// subsets of sinks are known are bottom of the graph
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
	comp.push_back(start);
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

	// for(int i=0;i<output.size();i++)
	// {
	// 	for(int j=0;j<output[i].size();j++)
	// 	{
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	unordered_set< unordered_set<int>* >* output2 = new unordered_set< unordered_set<int>* >();
	// set< set<int>* >* output2 = new set < set<int>* >();
	for(int i=0;i<output.size();i++)
	{
		unordered_set <int>* comp = new unordered_set<int>();
		for(int j=0;j<output[i].size();j++)
		{
			comp->insert(output[i][j]);
		}
		output2->insert(comp);
		
	}
	int c = 0;
	int d = 0;
	int e = 0;

	// unordered_set< unordered_set<int>* >* output = getcomp(edges,V,p);
	unordered_set< unordered_set<int>* > :: iterator it=(output2)->begin();
	unordered_set<int>* suni;
	while(it!=(output2)->end())
	{
		unordered_set<int>* cur = *it;
		unordered_set<int> :: iterator jt = (cur)->begin();
		unordered_set<int> :: iterator jt2 = (cur)->begin();
		while(jt!=(cur)->end())
		{
			e+=1;
			for(int i=0;i<edges[*jt].size();i++)
			{
				int adj = edges[*jt][i];
				if(cur->find(adj)!=cur->end())
				{
					c+=1;
				}
			}
			if(c==edges[*jt].size())
			{
				// cout << *jt + 1 << " ";
				d+=1;
			}
			c=0;
			jt++;
		}
		if(d==e)
		{
			while(jt2!=(cur)->end())
			{
				cout << *jt2 + 1<< " ";
				jt2++;
			}
		}
		it++;
	}

	// vector<int> arr;
	// for(int i=0;i<output.size();i++)
	// {
	// 	set<int> temp;
	// 	for(int j=0;j<output[i].size();j++)
	// 	{
	// 		temp.insert(output[i][j]);
	// 	}

	// 	for(int k=0;k<output[i].size();k++)
	// 	{
	// 		int key = output[i][k];
	// 		int value = 0;
	// 		for(int h=0;h<edges[key].size();h++)
	// 		{
	// 			int adj = edges[key][h];
	// 			if(temp.find(adj)!=temp.end())
	// 			{
	// 				value+=1;
	// 				continue;
	// 			}

	// 		}
	// 		if(value==edges[key].size())
	// 		{
	// 			arr.push_back(i);
	// 		}
	// 	}
	// }
	// for(int i=0;i<arr.size();i++)
	// {
	// 	int index = arr[i];
	// 	for(int j=0;j<output[index].size();j++)
	// 	{
	// 		cout << output[index][j]+1 << " ";
	// 	}
	// 	cout << endl;
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