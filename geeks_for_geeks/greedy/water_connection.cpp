#include<bits/stdc++.h>
using namespace std;


void dfs(int** adj,int root,pair<int,pair<int,int>>& temp,int n,int& result)
{
	int check = 0;
	for(int i=0;i<n;i++)
	{
		if(adj[root][i]!=INT_MAX)
		{
			check = 1;
			result = min(result,adj[root][i]);
			dfs(adj,i,temp,n,result);
		}
	}
	if(check==0)
	{
		(temp.second).first = root;
		return ;
	}
	return ;
}

void solve(int** adj,int n,vector<int>& indegree)
{
	if(n==0)
	{
		return ;
	}
	int count = 0;
	vector<pair<int,pair<int,int>>> output;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			count+=1;
			pair<int,pair<int,int>> temp;
			temp.first = i;
			int result = INT_MAX;
			dfs(adj,i,temp,n,result);
			if((temp.second).first==i)
			{
				count-=1;
				continue;
			}
			(temp.second).second = result;
			output.push_back(temp);
		}
	}
	cout << count << endl;
	for(int i=0;i<output.size();i++)
	{
		cout << output[i].first + 1 << " " << output[i].second.first + 1<< " " << (output[i].second).second << endl;
	}
	return ;

}

int main()
{
	int n,m;
	cin >> n >> m;
	int** adj = new int*[n];
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++)
	{
		adj[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			adj[i][j]=INT_MAX;
		}
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		indegree[b-1]+=1;
		adj[a-1][b-1]=c;
	}
	solve(adj,n,indegree);



	
	return 0;
}