#include<bits/stdc++.h>
using namespace std;



int count_visited(bool** visited,int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(visited[i][j])
			{
				count+=1;
			}
		}
	}
	return count;
}



void make_zero(bool** visited,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			visited[i][j]=false;
		}
	}
	return ;
}


bool ispossible(int** arr,int n,bool** visited,int si,int sj)
{
	if(si<0 || si >=n || sj<0 || sj>=n)
	{
		return false;
	}
	if(visited[si][sj]==true)
	{
		return false;
	}
	if(arr[si][sj]!=1)
	{
		return false;
	}
	return true;
}


void solve2(int** arr,int n,bool** visited,int si,int sj)
{
	visited[si][sj]=true;
	int first[4]={-1,1,0,0};
	int second[4]={0,0,-1,1};
	for(int i=0;i<4;i++)
	{
		int x = si+first[i];
		int y = sj+second[i];
		if(ispossible(arr,n,visited,x,y))
		{	
			solve2(arr,n,visited,x,y);
		}
	}
	return ;
}




int solve(int** arr,int n)
{
	bool** visited = new bool*[n];
	int max_ = INT_MIN;
	for(int i=0;i<n;i++)
	{
		visited[i]=new bool[n];
		for(int j=0;j<n;j++)
		{
			visited[i][j]=false;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1)
			{
				solve2(arr,n,visited,i,j);
				int result = count_visited(visited,n);
				if(result > max_)
				{
					max_ = result;
				}
				make_zero(visited,n);

			}
		}
	}

	return max_;
	

}



int main()
{
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve(arr,n) << endl;
	return 0;
}