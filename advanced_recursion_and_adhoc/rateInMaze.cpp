#include<bits/stdc++.h>
using namespace std;




void mazeHelper(int n,int  maze[][20],int **arr,int x,int y)
{
	//cout << "yes-1" << endl;
	if(x==n-1 && y==n-1)
	{
		arr[x][y]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return ;
	}

	if(x<0 || y<0 || x>=n || y>=n || maze[x][y]==0 || arr[x][y]==1)
	{
		return ;
	}
	arr[x][y]=1;
	mazeHelper(n,maze,arr,x-1,y);// up
	mazeHelper(n,maze,arr,x+1,y);//down
	mazeHelper(n,maze,arr,x,y-1); // left
	mazeHelper(n,maze,arr,x,y+1); // right
	arr[x][y]=0;// backtrack after exploring all paths
}

void rateInMaze(int n,int maze[][20])
{
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
	}
	//cout << "yes" << endl;
	//memset(arr,0,n*n*sizeof(int));
	//cout << "yes-1" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}

	mazeHelper(n,maze,arr,0,0);

}

int main()
{
	int n;
	cin >> n;
	int maze[20][20]={{1,1,0},{1,1,1},{0,1,1}};
	
	rateInMaze(n,maze);
	return 0;
}