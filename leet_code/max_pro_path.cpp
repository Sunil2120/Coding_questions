#include<bits/stdc++.h>
using namespace std;


int find_maxvertex(double* dist,bool* visited,int n)
{
	double max_value = INT_MIN;
	int max_i = -1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==true)
		{
			continue;
		}
		else
		{
			if(dist[i] > max_value)
			{
				max_value = dist[i];
				max_i = i;
			}
		}
	}
	return max_i;
}


double solve(double** arr,int n,int start,int end)
{
	double* dist = new double[n];
	for(int i=0;i<n;i++)
	{
		dist[i]=0;
	}
	bool* visited = new bool[n]();
	dist[start]=1;
	for(int i=0;i<n-1;i++)
	{
		int index = find_maxvertex(dist,visited,n);
		visited[index]=true;
		for(int j=0;j<n;j++)
		{
			if(j==index)
			{
				continue;
			}
			if(visited[j]==true)
			{
				continue;
			}
			if(arr[index][j]!=0 && visited[j]==false)
			{
				double cur_distance = dist[index]*arr[index][j];
				dist[j]=max(dist[j],cur_distance);
			}
		}
	}
	double ans = dist[end];
	delete[] dist;
	delete[] visited;
	if(ans==0)
	{
		return 0;
	}
	else
	{
		return ans;
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	int edges;
	cin >> edges;
	double** arr = new double*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new double[n];
		for(int j=0;j<n;j++)
		{
			arr[i][j]=-1;
		}
	}
	for(int i=0;i<edges;i++)
	{
		int f,s;
		double value;
		cin >> f >> s >> value;
		arr[f][s]=value;
		arr[s][f]=value;
	}
	int start,end;
	cin >> start >> end;
	cout << fixed << setprecision(4) <<  solve(arr,n,start,end) << endl;
	for(int i=0;i<n;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}