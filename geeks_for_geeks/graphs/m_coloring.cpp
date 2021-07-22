// graph colouring using Greedy Algorithm
#include<bits/stdc++.h>
using namespace std;

bool is_safe(unordered_map<int,vector<int>>& adj,int index,vector<int>& color,int c)
{
    for(int i=0;i<adj[index].size();i++)
    {
        if(color[adj[index][i]]==c)
        {
            return false;
        }
    }
    return true;
}


bool solve(unordered_map<int,vector<int>>& adj,int index,vector<int>& color,int V,int m)
{
    if(index==V)//all nodes are assigned with a color
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(is_safe(adj,index,color,i)==true)
        {
            color[index]=i;
            bool temp = solve(adj,index+1,color,V,m);
            if(temp)
            {
                return true;
            }
            color[index]=0;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin >> n >> m;
    int e;
    cin >> e;
    map<int,vector<int>> adj;
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin >> f >> s;
        adj[f-1].push_back(s-1);
        adj[s-1].push_back(f-1);
    }
    cout << solve(adj,n,m,e) << endl;
    return 0;
}