#include<bits/stdc++.h>
using namespace std;


struct node
{
	int src=0;
	int dest=0;
	int weight = 0;

};


int getparent(int index,int* parent)
{
	if(parent[index]==index)
	{
		return index;
	}
	return getparent(parent[index],parent);
}


bool check(int x,int y,vector< pair<int,int> > output)
{
	for(int i=0;i<output.size();i++)
	{
		int first = output[i].first;
		int second = output[i].second;
		if(first== x || first== y && second == x || second == y)
		{
			return true;
		}
	}
	return false;
}



void dfs(vector<int>* edges,int start,int parent,int v,bool* visited,int* in,int* low,int timer,vector<pair<int,int>>& temp)
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
			dfs(edges,adj,start,v,visited,in,low,timer,temp);
			if(low[adj] > in[start])// adj has no direct edge with the ancestors of start it's a bridge
			{
				// cout << start+1 << " " << adj+1 << " " << "is a bridge" << endl;
				temp.push_back(make_pair(start,adj));
			}
			low[start]=min(low[start],low[adj]);// 
		}
	}

}



vector< pair<int,int> > solve(vector<int>* edges,int v,int e)
{
	bool* visited = new bool[v];
	vector<pair<int,int>> output;
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
			dfs(edges,i,-1,v,visited,in,low,0,output);
		}
	}
	delete[] visited;
	delete[] in;
	delete[] low;
	return output;
}


void solve2(vector<int>* edges,map<int,vector<pair<int,int>>> hash, int v,int e,vector< pair<int,int> > output,vector<int> suni)
{
	bool* visited = new bool[v]();
	int* parent = new int[v];
	for(int i=0;i<v;i++)
	{
		parent[i]=i;
	}
	sort(suni.begin(),suni.end());
	for(int i=0;i<suni.size();i++)
	{
		cout << suni[i] << endl;
	}
	for(int i=0;i<suni.size();i++)
	{
		int first = suni[i];
		vector< pair<int,int>> temp = hash[first];
		if(temp.size()==1)
		{
			int src = getparent(temp[0].first,parent);
			int dest = getparent(temp[0].second,parent);
			if(src!=dest)
			{
				cout << temp[0].first << " " << temp[0].second  << " " <<"any" << endl;
				parent[src]=dest;
			}
			else
			{
				cout << temp[0].first << " " << temp[0].second  << " " <<"none" << endl;
			}
		}
		else
		{
			int count = 0;
			int sr =0;
			int des = 0;
			for(int i=0;i<temp.size();i++)
			{
				if(check(temp[i].first,temp[i].second,output))
				{
					cout << temp[i].first << " " << temp[i].second  << " " << "any" << endl;
					continue;
				}
				int src = getparent(temp[i].first,parent);
				int dest = getparent(temp[i].second,parent);
				if(src!=dest)
				{
					cout << temp[i].first << " " << temp[i].second  << " " <<"atleast one" << endl;
					// parent[src]=dest;
					sr = src;
					des = dest;
					count +=1;
				}
				else
				{
					cout << temp[i].first << " " << temp[i].second  << " " <<"none" << endl;
				}

			}
			if(count!=0)
			{
				parent[sr]=des;
			}
		}

	}
	delete[] visited;
	delete[] parent;
	return ;
}
int main()
{
	int v,e;
	cin >> v >> e;
	map<int,vector< pair<int,int>>> hash;
	vector<int> suni;
	set<int> ani;
	vector<int>* edges = new vector<int>[v];
	vector< pair<int,int> > output;
	for(int i=0;i<e;i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
		hash[w].push_back(make_pair(x-1,y-1));
		ani.insert(w);
	}
	set<int> :: iterator it=ani.begin();
	while(it!=ani.end())
	{
		suni.push_back(*it);
		it++;
	}
	output = solve(edges,v,e);
	for(int i=0;i<output.size();i++)
	{
		cout << output[i].first << " " << output[i].second << endl;
	}
	solve2(edges,hash,v,e,output,suni);
	
	return 0;
}