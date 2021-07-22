#include<bits/stdc++.h>
using namespace std;

//https://www.techiedelight.com/collect-maximum-value-coins-matrix/

bool isValid(int m,int n,int x,int y)
{
	if(x < 0 || x >= m || y < 0 || y>= n)
	{
		return false;
	}
	return true;
}

int solve2(int** matrix,int m,int n,int i,int x,int y)
{
	if(isValid(m,n,i,x)==false || isValid(m,n,i,y)==false)
	{
		return INT_MIN;
	}
	if(i==m-1)
	{
		if(x==0 && y==n-1)
		{
			//destination reached
			return (x==y)?(matrix[i][x]):(matrix[i][x]+matrix[i][y]);
		}
		return INT_MIN;//destination not reached
	}
	int coins =  INT_MIN;
	coins = max(coins,solve2(matrix,m,n,i+1,x,y));
	coins = max(coins,solve2(matrix,m,n,i+1,x,y-1));
	coins = max(coins,solve2(matrix,m,n,i+1,x,y+1));

	coins = max(coins,solve2(matrix,m,n,i+1,x-1,y));
	coins = max(coins,solve2(matrix,m,n,i+1,x-1,y-1));
	coins = max(coins,solve2(matrix,m,n,i+1,x-1,y+1));

	coins = max(coins,solve2(matrix,m,n,i+1,x+1,y));
	coins = max(coins,solve2(matrix,m,n,i+1,x+1,y-1));
	coins = max(coins,solve2(matrix,m,n,i+1,x+1,y+1));
	if(x==y)
	{
		return matrix[i][x]+coins;
	}
	else
	{
		return matrix[i][x]+matrix[i][y]+coins;
	}
	return 0;
}

int solve(int** matrix,int m,int n)
{
	return solve2(matrix,m,n,0,0,n-1);
}


int main()
{
	int m,n;
	cin >> m >> n;
	int** matrix = new int*[m];
	for(int i=0;i<m;i++)
	{
		matrix[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << solve(matrix,m,n) << endl;
	return 0;
}