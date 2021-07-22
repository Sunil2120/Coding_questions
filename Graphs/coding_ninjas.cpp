#include<bits/stdc++.h>
using namespace std;

bool ispossible(string* input,int n,int m,int si,int sj,string s,int count,bool** visited)
{
	
	if(si < 0 || si >= n || sj < 0 || sj > m)
	{
		return false;
	}
	if(visited[si][sj]==true)
	{
		return false;
	}
	if(input[si][sj] !=s[count])
	{
		return false;
	}
	return true;
}



bool solve(string* input,int n,int m,int si,int sj,bool** visited,string s,int count)
{
	visited[si][sj]=true;
	if(input[si][sj] == s[s.size() -1] && count == s.size() )
	{
		
		return true;
	}
	
	int first[8]={-1,1,0,0,-1,-1,1,1};
	int second[8]={0,0,-1,1,1,-1,1,-1};
	


	for(int i=0;i<8;i++)
	{
		int x = si + first[i];
		int y = sj + second[i];
		if(ispossible(input,n,m,x,y,s,count,visited))
		{
			
			visited[x][y]=true;
			bool temp = solve(input,n,m,x,y,visited,s,count+1);
		 	if(temp)
		 	{
				return temp;
		 	}
			visited[x][y]=false;
		}
	}

	return false;

}


void print(string* input,int n,int m,string str)
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
	vector< pair<int,int> > intial;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(input[i][j]=='C')
			{
				intial.push_back(make_pair(i,j));
			}
		}
	}
	for(int i=0;i<intial.size();i++)
	{
		if(solve(input,n,m,intial[i].first,intial[i].second,visited,str,1))
		{
			cout << "true" << endl;
			return ;
		}
	}
	cout << "false" << endl;
	for(int i=0;i<n;i++)
	{
		delete[] visited[i];
	}
	delete[] visited;
	return ;
}


int main()
{
	int n,m;
	cin >> n >> m;
	string* input = new string[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	print(input,n,m,"CODINGNINJA");

	return 0;
}