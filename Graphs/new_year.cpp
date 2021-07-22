#include<bits/stdc++.h>
using namespace std;


bool dfs(map<int,vector<int>> hash,int start,int q,bool* visited)
{
	if(start==q)
	{
		return true;
	}
	for(int i=0;i<hash[start].size();i++)
	{
		int adj = hash[start][i];
		if(visited[adj]==false)// not yet visited
		{
			bool temp = dfs(hash,adj,q,visited);
			if(temp)// found the required element
			{
				return true;
			}
		}
	}
	return false;

}

bool solve(int* arr,int n,int q)
{
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	map<int,vector<int> >hash;
	for(int i=1;i<n;i++)
	{
		hash[i].push_back(i+arr[i]);
	}
	bool ans = dfs(hash,1,q,visited);
	delete[] visited;
	return ans;
}


int main()
{
	int n,q;
	cin >> n >> q;
	int* arr = new int[n];
	for(int i=1;i<n;i++)
	{
		cin >> arr[i];
	}
	arr[0]=-1;
	bool ans = solve(arr,n,q);
	if(ans)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	delete[] arr;
	return 0;
}
