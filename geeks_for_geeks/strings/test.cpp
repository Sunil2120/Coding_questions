#include<bits/stdc++.h>
using namespace std;


bool ispossible(int x,int y,int m,int n,bool** visited)
{
    if(x < 0 || x >= m || y<0 || y>=n)
    {
        return false;
    }
    if(visited[x][y]==true)
    {
        return false;
    }
    return true;
}
int solve2(char** arr,int x,int y,string search,int cur,bool** visited,int m,int n)
{
    if(cur >= search.size())
    {
        return 1;
    }
    visited[x][y]=true;
    int row[8]={-1,1,0,0,-1,-1,1,1};
    int col[8]={0,0,-1,1,1,-1,1,-1};
    int count = 0;
    for(int i=0;i<8;i++)
    {
        int rx = x+row[i];
        int ry = y+col[i];
        if(ispossible(rx,ry,m,n,visited)==true && arr[rx][ry]==search[cur])
        {
            count+=solve2(arr,rx,ry,search,cur+1,visited,m,n);
        }

    }
    visited[x][y]=false;
    return count;
}

int solve(char** arr,int m,int n,string search)
{
    int total = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==search[0])
            {
                bool** visited = new bool*[m];
                for(int i=0;i<m;i++)
                {
                    visited[i]=new bool[n]();
                }
                total+=solve2(arr,i,j,search,1,visited,m,n);

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
    cout << solve(arr,m,n,search) << endl;
}