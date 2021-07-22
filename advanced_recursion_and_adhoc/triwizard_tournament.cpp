#include<bits/stdc++.h>
using namespace std;


pair<int,int> find_min(map<int,vector< pair<int,int> >> hash,int start,bool* visited)
{
	vector<pair<int,int>> temp = hash[start];
	int min_value = INT_MAX;
	int min_index = -1;
	for(int i=0;i<temp.size();i++)
	{
		pair<int,int> suni = temp[i];
		if(visited[suni.first]==true)
		{
			continue;
		}
		if(suni.second < min_value )
		{
			min_value = suni.second;
			min_index = suni.first;
		}
	}
	return make_pair(min_index,min_value);

}

void dfs(map<int,vector< pair<int,int> >> hash,int start,bool* visited,int& count)
{
	visited[start]=true;
	pair<int,int> next = find_min(hash,start,visited);
	if(next.first==-1)
	{
		return ;
	}
	//cout << start+1 << " " << next.first+1 << " " << next.second << endl;
	count+=next.second;
	dfs(hash,next.first,visited,count);
}


void dfs2(map<int,vector< pair<int,int>> >& hash,int start,bool* visited)
{
	visited[start]=true;
	for(int i=0;i<hash[start].size();i++)
	{
		int next = hash[start][i].first;
		if(visited[next]==true)
		{
			continue;
		}
		dfs2(hash,next,visited);
	}
	return ;
}

bool disconnected(map<int,vector< pair<int,int>> >& hash,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}

	dfs2(hash,0,visited);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			return true;
		}
	}
	delete[] visited;
	return false;
}

void solve(map<int,vector< pair<int,int> >> hash,int n,int m)
{
	bool* visited = new bool[n];
	int ani_min = INT_MAX;
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		int count = 0;
		dfs(hash,i,visited,count);
		int check = 0;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==false)
			{
				check=1;
			}
			visited[i]=false;
		}
		if(check==0)
		{
			if(count < ani_min)
			{
				ani_min = count;
			}
		}

	}
	cout << ani_min << endl;
	delete[] visited;
	return ;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		map<int,vector< pair<int,int> >> hash;
		for(int i=0;i<m;i++)
		{
			int f,s,v;
			cin >> f >> s >> v;
			hash[f-1].push_back(make_pair(s-1,v));
			hash[s-1].push_back(make_pair(f-1,v));
		}
		if(disconnected(hash,n)==false)
		{
			solve(hash,n,m);
		}
		else
		{
			cout << -1 << endl;
		}
		
	}
	return 0;
	
}