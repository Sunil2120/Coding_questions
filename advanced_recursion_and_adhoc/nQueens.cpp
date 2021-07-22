#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool canPlace(int n,int row,int col)
{
	// same col
	for(int i=row-1;i>=0 ;i--)
	{
		if(board[i][col]==1)
		{
			return false;
		}
	}
	// left upper diagonal
	for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--)
	{
		if(board[i][j]==1)
		{
			return false;
		}
	}
	// right upper diagonal
	for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
	{
		if(board[i][j]==1)
		{
			return false;
		}
	}
	return true;
}


void Queens(int n,int row)
{
	//base case
	if(row==n)// we have covered all possible paths
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(canPlace(n,row,i))
		{
			board[row][i]=1;
			Queens(n,row+1);// if not possible to place or base case is it this will return so stops so we should backtrack
			board[row][i]=0;
		}
	}
	return ;
}


void placeQueens(int n)
{
	memset(board,0,11*11*sizeof(int));
	Queens(n,0);
	return ;

}
int main()
{
	int n;
	cin >> n;
	placeQueens(n);
	return 0;
}