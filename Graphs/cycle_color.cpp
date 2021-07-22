#include<bits/stdc++.h>
using namespace std;


bool ispossible(string* input,int n,int m,char suni,bool** visited,int si,int sj)
{
	if(si < 0 || si >=n || sj <0 || sj >=m)
	{
		return false;
	}
	if(visited[si][sj])
	{
		return false;
	}
	if(input[si][sj]!=suni)
	{
		return false;
	}
	return true;
}



bool check(string* input,int n,int m,char suni,bool** visited,int si,int sj,int count,pair<int,int> f)
{

	int first[8]={-1,1,0,0};
	int second[8]={0,0,-1,1};

	for(int i=0;i<4;i++)
	{
		int x = si + first[i];
		int y = sj + second[i];
		
		if(x==f.first && y==f.second && input[x][y]==suni && count>=4)
		{
			return true;
		}
		if(ispossible(input,n,m,suni,visited,x,y))
		{
			visited[x][y]=true;
			bool temp = check(input,n,m,suni,visited,x,y,count+1,f);
			if(temp)
			{
				return true;
				
			}
			visited[x][y]=false;//to make all zeores once it is finish
		}
	}
	return false;

}



bool solve(string* input,int n,int m)
{
	bool** visited = new bool*[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
		{
			visited[i][j]=false;
		}
	}

	for(int i=0;i<26;i++)
	{
		char suni = (char)(i + 'A');
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(input[j][k]==suni)
				{
					visited[j][k]=true;
					bool temp = check(input,n,m,suni,visited,j,k,1,make_pair(j,k));
					if(temp)
					{
						 cout << j << " " << k << endl;
						return temp;
					}
					visited[j][k]=false;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		delete[] visited[i];
	}
	delete[] visited;
	return false;
			
}

int main()
{
	int n,m;
	cin >> n >> m;
	string* input = new string[n];
	//int* count = new int[26]();
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << solve(input,n,m) << endl;
	delete[] input;
	return 0;
}