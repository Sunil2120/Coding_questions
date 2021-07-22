#include<bits/stdc++.h>
using namespace std;

void dfs(map<int,vector<int>> hash,int start,int count,bool* visited,vector<int>& result)
{
    visited[start]=true;
    int check = 0;
    for(int i=0;i<hash[start].size();i++)
    {
        int cur = hash[start][i];
        if(visited[cur]==true)
        {
            continue;
        }
        if(visited[cur]==false)
        {
            check = 1;
            dfs(hash,cur,count+1,visited,result);
        }
    }
    if(check==0)// it has no unvisited neighbours
    {
        result.push_back(count);
    }
    return;

}

double solve(map<int,vector<int>> hash,int n,int cost)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<int> result;
    dfs(hash,0,0,visited,result);
    double output = 0;
    for(int i=0;i<result.size();i++)
    {
        output += result[i]*cost;
    }
    delete[] visited;
    return output/result.size();
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,cost;
        cin >> n >> cost;
        map<int,vector<int>> hash;
        for(int i=0;i<n-1;i++)
        {
            int f,s;
            cin >> f >> s;
            hash[f-1].push_back(s-1);
            hash[s-1].push_back(f-1);
        }
        cout << fixed << setprecision(4) << solve(hash,n,cost) << endl;
    }
}