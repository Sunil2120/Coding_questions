// Count of number of given string in 2D character array
// Last Updated: 31-01-2020
// Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array such that individual characters can be present left to right, right to left, 
// top to down or down to top.

#include<bits/stdc++.h>
using namespace std;

bool ispossible(int rx,int ry,int m,int n)
{
	if(rx <0 || rx >=m || ry<0 || ry>=n)
	{
		return false;
	}
	return true;
}

int helper(char** arr,string search,int cur_index,int x,int y,int m,int n)
{
	if(cur_index==search.size())
	{
		return 1;
	}
	int row[4] ={-1,1,0,0};
	int col[4]= {0,0,-1,1};
	int count = 0;
	for(int i=0;i<4;i++)
	{
		int rx = x+row[i];
		int ry = y+col[i];
		if(ispossible(rx,ry,m,n)==true && arr[rx][ry]==search[cur_index])
		{
			count+=helper(arr,search,cur_index+1,rx,ry,m,n);
		}
	}
	return count;

}


int solve(char** arr,string search,int m,int n)
{
	int total = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==search[0])
			{
				total+= helper(arr,search,1,i,j,m,n);
			}
		}
	}
	return total;

}


int main()
{
	int m,n;
	cin >> m >> n;
	char** arr = new char*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new char[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	string search;
	cin >> search;
	cout << solve(arr,search,m,n) << endl;
}