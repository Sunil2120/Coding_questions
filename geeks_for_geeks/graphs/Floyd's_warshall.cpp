// floyd's warshall algorithm is used to find the shortest path b/w all pair of vertices
// it can also be used to find the presence of negative weighted cylce
// after for loop if d[i][i] < 0 then graph has negative weighted cylce
// it works for  both directed and undirected
// time complexity O(V^3);

#include<bits/stdc++.h>
using namespace std;

void solve(int** arr,int n,int m)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][k]!=INT_MAX && arr[k][j]!=INT_MAX)
				{
					if(arr[i][j] > arr[i][k]+arr[k][j])
					{
						arr[i][j]=arr[i][k]+arr[k][j];
					}
				}
			}
		}
	}
	// check for negative weighted cycle
	for(int i=0;i<n;i++)
	{
		if(arr[i][i] < 0)
		{
			cout << "negative cycle" << endl;
			return ;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return ;

}

int main()
{
	int n,m;
	cin >> n >> m;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			arr[i][j]=INT_MAX;
		}
		arr[i][i]=0;// self loops
	}
	for(int i=0;i<m;i++)
	{
		int f,s,w;
		cin >> f >> s >> w;
		// directed graph
		arr[f][s]=w;
	}
	// arr[i][j]==INT_MAX no edge b/w i and j
	solve(arr,n,m);
	for(int i=0;i<n;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;

}
