#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		int** adj = new int*[n];
		for(int i=0;i<n;i++)
		{
			adj[i]=new int[n];
			for(int j=0;j<n;j++)
			{
				adj[i][j]=-1;
			}
		}
		for(int i=0;i<m;i++)
		{
			int f,s,value;
			cin >> f >> s >> value;
			if(adj[f-1][s-1]==-1)
			{
				adj[f-1][s-1]=value;
				adj[s-1][f-1]=value;
			}
			else
			{
				if(value < adj[f-1][s-1])
				{
					adj[f-1][s-1]=value;
					adj[s-1][f-1]=value;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			adj[i][i]=0;
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(adj[i][k]!=-1 && adj[k][j]!=-1)
					{
						if(adj[i][j]==-1)
						{
							adj[i][j]=adj[i][k]+adj[k][j];
						}
						else
						{
							if(adj[i][j] > (adj[i][k]+adj[k][j]))
							{
								adj[i][j]= adj[i][k]+adj[k][j];
							}
						}
					}
				}
			}
		}
		int k = adj[0][0];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(adj[i][j]==-1)
				{
					k=-1;
					break;
				}
				else
				{
					if(adj[i][j] > k)
					{
						k= adj[i][j];
					}
				}
				if(k==-1)
				{
					break;
				}
			}
		}

		cout << k << endl;
		for(int i=0;i<n;i++)
		{
			delete[] adj[i];
		}
		delete[] adj;
	}
	return 0;

}