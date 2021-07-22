// min steps for a knight to travel from source to dest
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	int count = 0;
};

bool ispossible(int x,int y,int n,int m)
{
	if( x<0 || x>=n || y < 0 || y>=m)
	{
		return false;
	}
	return true;
}

int solve(int** board,int x,int y,int dx,int dy,int n,int m)
{

	int row[8] = {-1,-1,1,1,2,2,-2,-2};
	int col[8] = {-2,2,-2,2,-1,+1,1,-1};
	queue<node*> Q;
	board[x][y]=1;
	node* temp = new node();
	temp->x = x;
	temp->y = y;
	temp->count = 0;
	Q.push(temp);
	while(!Q.empty())
	{
		node* cur = Q.front();
		Q.pop();
		// explore it's neighbours
		for(int i=0;i<8;i++)
		{
			int rx = row[i]+cur->x;
			int ry = col[i]+cur->y;
			if(ispossible(rx,ry,n,m)==true && board[rx][ry]==0)// not visited
			{
				node* temp = new node();
				temp->x = rx;
				temp->y = ry;
				temp->count = cur->count+1;
				board[rx][ry]=1;
				Q.push(temp);
				if(rx==dx && ry==dy)
				{
					return temp->count;
				}
			}
		}
	}
	return -1;

}

int main()
{
	int n,m;
	cin >> n >> m;
	int** board = new int*[n];
	for(int i=0;i<n;i++)
	{
		board[i]=new int[n]();
	}
	int sx,sy,dx,dy;
	cin >> sx >> sy >> dx >> dy;
	cout << solve(board,sx,sy,dx,dy,n,m) << endl;
}