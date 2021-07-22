#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y;
	int val;
};
typedef struct node node;

int solve(int** arr,int m,int n)
{
	queue<node*> Q;
	node* temp = new node();
	temp->x = 0;
	temp->y = 0;
	temp->val = arr[0][0];
	bool** visited = new bool*[m];
	for(int i=0;i<m;i++)
	{
		visited[i]=new bool[n]();
	}
	Q.push(temp);
	visited[0][0]=true;
	while(!Q.empty())
	{
		node* cur = Q.front();
		Q.pop();
		int sx = cur->x;
		int sy = cur->y;
		int val = cur->val;
		// explore it's neighbours
		// right
		if(sy+1 < n && visited[sx][sy+1]==false)
		{
			node* temp1 = new node();
			temp1->x = sx;
			temp1->y = sy+1;
			temp1->val = val*arr[sx][sy+1];
			visited[sx][sy+1]=true;
			Q.push(temp1);
			if(temp1->x ==m-1 && temp1->y==n-1)
			{
				return temp1->val;
			}
		}
		// down
		if(sx+1 < m && visited[sx+1][sy]==false)
		{
			node* temp2 = new node();
			temp2->x = sx+1;
			temp2->y = sy;
			temp2->val = val*arr[sx+1][sy];
			visited[sx+1][sy]=true;
			Q.push(temp2);
			if(temp2->x == m-1 && temp2->y == n-1)
			{
				return temp2->val;
			}
		}
	}
	return -1;
}


int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
			arr[i][j]=-1*arr[i][j];
		}
	}
	cout << solve(arr,m,n) << endl;
}