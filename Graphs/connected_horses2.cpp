#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


struct node
{
	int start=-1;
	int end = -1;
	int count=-1;
};

int check(int x,int y,node* input,int e)
{

	for(int i=0;i<e;i++)
	{
		node cur = input[i];
		if(x==cur.start && y==cur.end)
		{
			return cur.count;
		}
	}
	return -1;
}

long long factorial(int n)
{
	long long* fac = new long long[n+1];
	fac[0]=1;
	fac[1]=1;
	for(int i=2;i<=n;i++)
	{
		fac[i]= i * fac[i-1];
		fac[i]=fac[i]%MOD;
	}
	long long ans = fac[n];
	delete[] fac;
	return ans;
}


void dfs(map<int,vector<int>> hash,int start,int& count,bool* visited)
{
	visited[start]=true;
	count+=1;
	for(int i=0;i<hash[start].size();i++)
	{
		int adj = hash[start][i];
		if(visited[adj]==false)
		{
			dfs(hash,adj,count,visited);
		}
	}
	return ;
}
void  solve(map<int,vector<int>> hash,int e)
{
	long long total = 1;
	bool* visited = new bool[e]();
	for(int i=0;i<e;i++)
	{
		if(visited[i]==false)
		{
			int count = 0;
			dfs(hash,i,count,visited);
			total = total * factorial(count);
			total = total%MOD;
		}
	}
	cout << total << endl;
	delete[] visited;
	return ;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,e;
		cin >> n >> m >> e;
		node* input = new node[e];
		for(int i=0;i<e;i++)
		{
			int s,e;
			cin >> s >> e;
			input[i].start = s-1;
			input[i].end = e-1;
			input[i].count=i;
		}
		map<int,vector<int>> hash;
		int x[8]={-2,-2,2,2,1,1,-1,-1};
		int y[8]={-1,1,-1,1,2,-2,-2,2};

		for(int i=0;i<e;i++)
		{
			node cur = input[i];
			for(int j=0;j<8;j++)
			{
				int x_i = cur.start + x[j];
				int y_j = cur.end + y[j];
				if(x_i < 0 || x_i >=n || y_j <0 || y_j >=m)
				{
					continue;
				}
				int ch = check(x_i,y_j,input,e);
				if(ch!=-1)
				{
					hash[cur.count].push_back(ch);
				}
			}
		}

		// map<int,vector<int>> :: iterator it;
		// for(it=hash.begin();it!=hash.end();it++)
		// {
		// 	cout << it->first << " ";
		// 	for(int i=0;i<(it->second).size();i++)
		// 	{
		// 		cout << (it->second)[i] << " ";
		// 	}
		// 	cout << endl;
		// }
		solve(hash,e);
		delete[] input;
	}
	
	return 0;
}