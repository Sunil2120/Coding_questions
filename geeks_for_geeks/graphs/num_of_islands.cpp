#include<bits/stdc++.h>
using namespace std;

bool ispossible(int x,int y,int N,int M)
{
    if(x < 0 || x >= N || y < 0 || y >=M)
    {
        return false;
    }
    return true;
}

void bfs(int x,int y,int** A,bool** visited,int N,int M)
{
    cout << x << " " << y << endl;
    int row[8] = {-1,1,0,0,-1,-1,1,1};
    int col[8] = {0,0,-1,1,-1,1,-1,1};
    queue< pair<int,int> > Q;
    visited[x][y]=true;
    Q.push(make_pair(x,y));
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        // explore it's neighbours
        for(int i=0;i<8;i++)
        {
            int rx = cur.first + row[i];
            int ry = cur.second + col[i];
            if(ispossible(rx,ry,N,M)==true && A[rx][ry]==1 && visited[rx][ry]==false)
            {
                visited[rx][ry]=true;
                Q.push(make_pair(rx,ry));
            }
        }
    }
    return ;
}
int findIslands(int** A, int N, int M) {

    bool** visited = new bool*[N];
    int count = 0;
    for(int i=0;i<N;i++)
    {
        visited[i]=new bool[M]();
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(visited[i][j]==false && A[i][j]==1)
            {
                count+=1;
                bfs(i,j,A,visited,N,M);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
       
            delete[] visited[i];
     
    }
    delete[] visited;
    return count;
}


int main()
{
    int N,M;
    cin >> N >> M;
    int** arr = new int*[N];
    for(int i=0;i<N;i++)
    {
        arr[i]=new int[M];
        for(int j=0;j<M;j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << findIslands(arr,N,M) << endl;
    return 0;
}
