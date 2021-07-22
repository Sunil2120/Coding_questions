#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int>* edges,int V,int start,bool* visited,unordered_set<int>* component,int* p)
{
	visited[start]=true;
	component->insert(p[start]);
	for(int i=0;i<edges[start].size();i++)
	{
		if(visited[edges[start][i]])
		{
			continue;
		}
		dfs(edges,V,edges[start][i],visited,component,p);
	}
	return ;
}


unordered_set< unordered_set<int>* >* getcomp(vector<int>* edges,int V,int* p)
{
	bool* visited = new bool[V];
	unordered_set< unordered_set<int>* >* output = new unordered_set< unordered_set<int>* >();
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			unordered_set<int>* component = new unordered_set<int>();
			dfs(edges,V,i,visited,component,p);
			output->insert(component);
		}
	}
	delete[] visited;
	return output;
}



int main()
{
	int V,E;
	cin >> V >> E;
	int* p = new int[V];
	int* q = new int[V];
	for(int i=0;i<V;i++)
	{
		cin >> p[i];
	}
	for(int i=0;i<V;i++)
	{
		cin >> q[i];
	}
	vector<int>* edges = new vector<int>[V];
	for(int i=0;i<E;i++)
	{
		int start,end;
		cin >> start >> end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}
	unordered_set< unordered_set<int>* >* output = getcomp(edges,V,p);
	unordered_set< unordered_set<int>* >* output2 = getcomp(edges,V,q);
	unordered_set< unordered_set<int>* > :: iterator it=(output)->begin();
	unordered_set< unordered_set<int>* > :: iterator it2=(output2)->begin();
	int check = 0;

	while(it!=(output)->end())
	{
		unordered_set<int>* cur = *it;
		unordered_set<int>* cur2 = *it2;
		unordered_set<int> :: iterator jt = (cur)->begin();
	 	while(jt!=(cur)->end())
	 	{
	// 		cout << *jt << " ";
	// 		jt++;
	 		if(cur2->find(*jt)==cur2->end())
	 		{
	 			cout << "NO" << endl;
	 			check = 1;
	 			break;

	 		}
	 		jt++;
	 	}
	 	if(check==1)
	 	{
	 		break;
	 	}
	// 	cout << endl;
	 	it++;
	 	it2++;
	}

	if(check==0)
	{
		cout << "YES" << endl;
	}


	delete[] edges;
	return 0;
}