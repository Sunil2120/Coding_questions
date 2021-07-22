#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


long long factorial(int n)
{
	long long* dp = new long long[n+1]();
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=i*dp[i-1];
		dp[i]=dp[i]%MOD;
	}
	long long ans = dp[n];
	delete[] dp;
	return ans;

}


bool ispossible(int** board,int x,int y,int N,int M)
{
	
	if(x<0 || x>=N || y<0 || y>=M)
	{
		return false;
	}
	if(board[x][y]==0)
	{
		return false;
	}
	return true;
}

void bfs(int start,bool* visited,map<int,vector<int>> hash,int &count)
{
	visited[start]=true;
	count+=1;
	for(int i=0;i<hash[start].size();i++)
	{
		if(hash[start][i]==start)
		{
			continue;
		}
		if(visited[ hash[start][i]]==true)
		{
			continue;
		}
		bfs(hash[start][i],visited,hash,count);
	}
	return ;
}


long long solve(int Q,map<int,vector<int>>  hash)
{
	bool* visited = new bool[Q];
	for(int i=0;i<Q;i++)
	{
		visited[i]=false;
	}
	long long total = 1;
	for(int i=0;i<Q;i++)
	{
		if(visited[i]==false)
		{
			int count = 0;
			bfs(i,visited,hash,count);
			total = total * factorial(count);
			total=total%MOD;
		}
	}
	delete[] visited;
	return total;

}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N,M,Q;
		cin >> N >> M >> Q;
		int count = 0;
		int** board = new int*[N];
		for(int i=0;i<N;i++)
		{
			board[i]=new int[M];
			for(int j=0;j<M;j++)
			{
				board[i][j]=0;
			}
		}
		map<int,vector<int>> hash;
		for(int i=0;i<Q;i++)
		{
			int x,y;
			cin >> x >> y;
			count+=1;
			board[x-1][y-1]=count;
		}



		int x[8]={-2,-2,2,2,1,1,-1,-1};
		int y[8]={-1,1,-1,1,2,-2,-2,2};

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(board[i][j]!=0)
				{
			
					for(int k=0;k<8;k++)
					{
						
						int x1 = i + x[k];
						int y1 =  j + y[k];
						if(ispossible(board,x1,y1,N,M)==true)
						{
							//arr[board[i][j]-1][board[x1][y1]-1]=1;
							hash[board[i][j]-1].push_back(board[x1][y1]-1);
						}

					}
				}
			}
		}

		cout << solve(Q,hash) << endl;

		for(int i=0;i<N;i++)
		{
			delete[] board[i];
		}
		delete[] board;

	}
	
	return 0;
}