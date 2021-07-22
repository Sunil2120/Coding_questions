#include<bits/stdc++.h>
using namespace std;


int solve(int** edges,int n,int e)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(edges[i][j]==1)
			{
				for(int k=0;k<n;k++)
				{
					if(k==j)
					{
						continue;
					}
					if(edges[j][k]==1)
					{
						if(edges[k][i]==1)
						{
							count+=1;
						}
					}
				}
			}
		}
	}
	return count/6;// because for each node we will get two directions so for 3 it will be 6 
}


int main()
{
	int n,e;
	cin >> n >> e;
	int** edges = new int*[n];
	for(int i=0;i<e;i++)
	{
		edges[i]=new int[n]();
	}
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		edges[a][b]=1;
		edges[b][a]=1;
	}
	cout << solve(edges,n,e) << endl;
	return 0;
}