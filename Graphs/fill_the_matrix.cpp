#include<bits/stdc++.h>
using namespace std;


int getparent(int* parent,int index,int n)
{
	if(parent[index]==index)
	{
		return index;
	}
	return getparent(parent,parent[index],n);
}


bool solve(map<int,vector<int> > edges,int start,int v,set<int>& visited)
{
	if(v==0)
	{
		return true;
	}
	set<int> s[2];
	queue<int> Q;
	// we will start from 0;
	Q.push(start);
	// we will insert 0 in first set
	s[0].insert(start);
	while(Q.size()!=0)
	{
		int cur = Q.front();
		visited.insert(cur);
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

bool solve2(map<int,vector<int> > edges,int v)
{
	set <int> visited;
	map<int,vector<int> > :: iterator it;
	for(it=edges.begin();it!=edges.end();it++)
	{
		if(visited.count(it->first)==0)
		{
			bool temp = solve(edges,it->first,v,visited);
			if(temp==false)
			{
				return false;
			}
		}
	}
	return true;
}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,q;
		cin >> n >> q;
		int** arr = new int*[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=new int[n];
			for(int j=0;j<n;j++)
			{
				arr[i][j]=-1;
			}
		}
		for(int i=0;i<q;i++)
		{
			int x,y,value;
			cin >> x >> y >> value;
			arr[x-1][y-1]=value;
		}
		// checking digonal
		int check = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
				{
					if(arr[i][j]==1)
					{
						cout << "no" << endl;
						check = 1;
						break;
					}
					arr[i][j]=0;
				}
			}
			if(check==1)
			{
				break;
			}

		}
		if(check==1)
		{
			continue;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==-1 || arr[j][i]==-1)
				{
					continue;
				}
				if(arr[i][j]!=arr[j][i])
				{
					cout << "no" << endl;
					check = 1;
					break;
				}
			}
			if(check==1)
			{
				break;
			}
		}
		if(check==1)
		{
			continue;
		}
		int* parent = new int[n];
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==0)
				{
					int x_i = getparent(parent,i,n);
					int y_j = getparent(parent,j,n);
					if(x_i!=y_j)
					{
						parent[x_i]=y_j;
					}
				}
			}
		}

		vector<int>* adj = new vector<int>[n];
		for(int i=0;i<n;i++)
		{
			int index = getparent(parent,i,n);
			adj[index].push_back(i);
		}
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<adj[i].size();j++)
		// 	{
		// 		cout << adj[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		map<int,vector<int>> hash;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==1)
				{
					int i_x = getparent(parent,i,n);
					int j_x = getparent(parent,j,n);
					if(i_x!=j_x)
					{
						hash[i_x].push_back(j_x);
						hash[j_x].push_back(i_x);
					}
				}
			}
		}

		bool ans = solve2(hash,n);
		if(ans)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
		delete[] adj;
		delete[] parent;
		for(int i=0;i<n;i++)
		{
			delete[] arr[i];
		}
		delete[] arr;

	}
	

	return 0;
}