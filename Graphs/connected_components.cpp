#include<bits/stdc++.h>
using namespace std;


void dfs(int** edges,int n,int start,bool* visited,vector<int> &temp)
{
	// temp.push_back(start);
	// visited[start]=true;
	// for(int i=0;i<n;i++)
	// {
	// 	if(i==start)
	// 	{
	// 		continue;
	// 	}
	// 	if(visited[i])
	// 	{
	// 		continue;
	// 	}
	// 	if(edges[start][i]==1)
	// 	{
	// 		dfs(edges,n,i,visited,temp);
	// 	}
	// }
	
    queue<int> Q;
    Q.push(start);
    visited[start]=true;
    while(!Q.empty())
    {
        temp.push_back(Q.front());
        for(int i=0;i<n;i++)
        {
            if(i==start)
            {
                continue;
            }
            if(edges[Q.front()][i]==1 && visited[i]==false)
            {
                Q.push(i);
                visited[i]=true;
            }
        }
        Q.pop();
    }
	return ;

}

vector< vector<int> > connected_components(int** edges,int n)
{
	bool* visited = new bool[n];
	vector< vector<int> > result;
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			vector<int> temp;
			dfs(edges,n,i,visited,temp);
			sort(temp.begin(),temp.end());
			result.push_back(temp);
		}
	}
	return result;

}

int main()
{
	int V,E;
	cin >> V >> E;
	int** edges = new int*[V];
	for(int i=0;i<V;i++)
	{
		edges[i]=new int[V]();
	}
	for(int i=0;i<E;i++)
	{
		int start ,end ;
		cin >> start >> end;
		edges[start][end]=1;
		edges[end][start]=1;
	}
	vector< vector<int> > result = connected_components(edges,V);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;

}