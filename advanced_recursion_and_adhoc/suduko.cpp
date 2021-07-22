#include<bits/stdc++.h>
#define N 9
using namespace std;


bool isEmpty(int board[][N],int& row,int& col)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(board[i][j]==0)
			{
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

bool rowSafe(int board[][N],int num,int row)
{
	for(int i=0;i<N;i++)
	{
		if(board[row][i]==num)
		{
			return false;
		}
	}
	return true;
}

bool colSafe(int board[][N],int num,int col)
{
	for(int i=0;i<N;i++)
	{
		if(board[i][col]==num)
		{
			return false;
		}
	}
	return true;
}


bool boxSafe(int board[][N],int num,int row,int col)
{
	int rowfact = row - (row%3);
	int colfact = col - (col%3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i+rowfact][j+colfact]==num)
			{
				return false;
			}
		}
	}
	return true;
}

bool canPlace(int board[][N],int num,int row,int col)
{
	//cout << "hello" << endl;
	return (rowSafe(board,num,row) && colSafe(board,num,col) && boxSafe(board,num,row,col));

}

bool solve_suduko(int board[][N])
{
	//cout << "hello" << endl;
	int row,col;
	if(isEmpty(board,row,col)==false)
	{
		
		return true;
	}
	//cout << row << " " << col << endl;
	for(int i=1;i<=N;i++)
	{
		if(canPlace(board,i,row,col))
		{
			board[row][col]=i;
			if(solve_suduko(board))
			{
				//cout << i << endl;
				return true;
			}
			board[row][col] = 0;
		}
	}
	//cout << "end" << endl;
	return false;

}


int main()
{
	int board[9][9];
	for(int i=0;i<N;i++)
	{
		string input;
		cin >> input;
		for(int j=0;j<N;j++)
		{
			board[i][j] = input[j] - '0';
		}
	}
	if(solve_suduko(board))
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "not possible" << endl;
	}
	
	
	return 0;
}