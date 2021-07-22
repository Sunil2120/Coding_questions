#include<bits/stdc++.h>
using namespace std;

bool has_path(int** edges,int n,int start,int end,bool* visited)
{
	if(edges[start][end]==1)
	{
		return true;
	}
	visited[start]=1;
	for(int i=0;i<n;i++)
	{
		if(start==i)
		{
			continue;
		}
		if(visited[i])
		{
			continue;
		}
		if(edges[start][i]==1)
		{
			bool temp = has_path(edges,n,i,end,visited);
			if(temp)
			{
				return temp;
			}
		}
	}
	return false;

}

void dfs2(int** edges,int n,int start,int end,bool* visited)
{
	cout << start << endl;
	visited[start]=true;
	if(edges[start][end]==1)
	{
		cout << end << endl;
		exit(0) ;
	}
	for(int i=0;i<n;i++)
	{
		if(start==i)
		{
			continue;
		}
		if(visited[i])
		{
			continue;
		}
		if(edges[start][i]==1)
		{
			dfs2(edges,n,i,end,visited);
		}
	}
	cout << " " << endl;
	return ;
}

// dfs is used
void get_path(int** edges,int n,int start,int end)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	dfs2(edges,n,start,end,visited);
	
	delete[] visited;
	return ;
}

void bfs2(int** edges,int n,int start,int end,bool* visited,map<int,int> &hash,int  &check)
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		//cout << q.front() << " " ;
		for(int i=0;i<n;i++)
		{
			// if(q.front()==end)
			// {
			// 	return ;
			// }
			if(i==q.front())
			{
				continue;
			}
			if(edges[q.front()][i]==1 && visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
				hash[i]=q.front();
				if(i==end)
				{
					//cout << endl;
					check = 1;
					return ;
				}
			}
		}
		q.pop();
	}
	return ;
}

// bfs is used
void printpath(map<int,int> hash,int start,int end)
{
	vector<int> result;
	int i = end;
	while(i!=start)
	{
		result.push_back(i);
		i=hash[i];
	}
	result.push_back(i);
	while(result.size()!=0)
	{
		cout << result.back() << endl;
		result.pop_back();
	}
	return ;
}

// bfs is used
void get_path2(int** edges,int n,int start ,int end)
{
	bool* visited = new bool[n];
	int check = 0;
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	map<int,int> hash;// key is node and value is parent_node
	bfs2(edges,n,start,end,visited,hash,check);
	if(check==0)
	{
		cout << "no path" << endl;
		return ;
	}

	printpath(hash,start,end);
	delete[] visited;
	return ;
}


int main()
{

	int n;//vertices
	cin >> n;
	int e;//edges
	cin >> e;
	int**edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	// bool* visited = new bool[n];
	// for(int i=0;i<n;i++)
	// {
	// 	visited[i]=false;
	// }
	int start ,end;
	cin >> start >> end;
	
	//cout << has_path(edges,n,start,end,visited) << endl;
	get_path2(edges,n,start,end);
	for(int i=0;i<n;i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
	//delete[] visited;

	return 0;

}