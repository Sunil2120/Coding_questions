// Flood fill algorithms
#include<bits/stdc++.h>
using namespace std;

bool ispossible(int x,int y,int m,int n)
{
	if(x < 0 || x >=m || y < 0 || y >= n)
	{
		return false;
	}
	return true;
}

void solve(int** arr,int m,int n,int x,int y,int newC,int prevC)
{
	arr[x][y]=newC;
	int row[4]={0,0,-1,1};
	int col[4]={-1,1,0,0};
	for(int i=0;i<4;i++)
	{
		int rx = x + row[i];
		int ry = y + col[i];
		if(ispossible(rx,ry,m,n)==true && arr[rx][ry]==prevC)
		{
			solve(arr,m,n,rx,ry,newC,prevC);
		}
	}
	return ;
}

int main()
{
	int n,m;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	int newC;
	int x,y;
	cin >> x >> y >> newC ;
	solve(arr,m,n,x,y,newC,arr[x][y]);
	for(int i=0;i<m;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}