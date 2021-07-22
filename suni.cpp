#include<bits/stdc++.h>
using namespace std;



void printpath(vector<int>& parent,int index)
{
	vector<int> temp;
	int i;
	for(i=index;parent[i]!=-1;i=parent[i])
	{
		temp.push_back(i);
	}
	temp.push_back(i);
	reverse(temp.begin(),temp.end());
	for(int i=0;i<temp.size();i++)
	{
		cout  << temp[i] << " ";
	}
	cout << endl;
	return ;

}

int find_min(vector<int>& dist,int n,vector<bool>& visited)
{
	int min_value = INT_MAX;
	int min_i = -1;
	for(int i=1;i<=n;i++)
	{

		if(dist[i] < min_value && visited[i]==false)
		{
			min_value = dist[i];
			min_i = i;
		}
	}
	return min_i;
}

void solve(int** adj,int n,int* h,set<int>& goal)
{
	vector<int> parent(n+1,-1);
	vector<bool> visited(n+1,false);
	vector<int> dist(n+1,INT_MAX);
	dist[1]=h[1];
	
	for(int j=0;j<n-1;j++)
	{
		int cur = find_min(dist,n,visited);
		visited[cur]=true;
		if(goal.find(cur)!=goal.end())
		{
			printpath(parent,cur);
		}
		// explore it's neighbours
		for(int i=1;i<=n;i++)
		{
			if(adj[cur][i]!=0 && adj[cur][i]!=-1 && visited[i]==false)
			{
				if(dist[cur]!=INT_MAX && dist[i] > dist[cur]+adj[cur][i]+h[i])
				{
					dist[i]=dist[cur]+adj[cur][i]+h[i];
					parent[i]=cur;
				}
			}
		}

	}
	return ;
	
}

int main()
{
	int n;
	cin >> n;
	int** adj = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		adj[i]=new int[n+1]();
		for(int j=0;j<=n;j++)
		{
			cin >> adj[i][j];
		}
	}

	int* h = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		cin >> h[i];
	}
	int g;
	cin >> g;
	set<int> goal;
	for(int i=0;i<g;i++)
	{
		int val;
		cin >> val;
		goal.insert(val);
	}
	solve(adj,n,h,goal);
	return 0;
}

// 0 0 0 0 0 0 0 0 0 0 0
// 0 0 5 9 -1 6 -1 -1 -1 -1 -1
// 0 -1 0 3 -1 -1 9 -1 -1 -1 -1 
// 0 -1 2 0 1 -1 -1 -1 -1 -1 -1
// 0 6 -1 -1 0 -1 -1 5 7 -1 -1
// 0 -1 -1 -1 2 0 -1 -1 -1 2 -1
// 0 -1 -1 -1 -1 -1 0 -1 -1 -1 -1
// 0 -1 -1 -1 -1 -1 -1 0 -1 -1 -1
// 0 -1 -1 -1 -1 2 -1 -1 0 -1 8
// 0 -1 -1 -1 -1 -1 -1 -1 -1 0 7
// 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 0