#include<bits/stdc++.h>

using namespace std;

int findparent(int* parent,int n,int index)
{
    if(parent[index]==index)
    {
        return index;
    }
    return findparent(parent,n,parent[index]);
}


int solve(int* arr,int n)
{
    int large = 0;
    // using union find algorithm
    for(int i=0;i<n;i++)
    {
        large = max(large,arr[i]);
    }
    int* parent = new int[large+1];
    for(int i=0;i<=large;i++)
    {
        parent[i]=i;
    }
    // find prime factors
    for(int i=0;i<n;i++)
    {
        for(int j=2;j<=sqrt(arr[i]);j++)
        {
            if(arr[i]%j == 0)
            {
               int x = findparent(parent,n,arr[i]);
               int y = findparent(parent,n,j);
               parent[x]=y;// belong to same set
               int temp  = arr[i]/j;
               y = findparent(parent,n,temp);
               x = findparent(parent,n,arr[i]);
               parent[x]=y;
            }
        }
    }
    map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        int x = findparent(parent,n,arr[i]);
        hash[x]+=1;
    }
    map<int,int> :: iterator it = hash.begin();
    int max_len = 0;
    for(it=hash.begin();it!=hash.end();it++)
    {
        max_len = max(max_len,it->second);
    }
    return max_len;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr,n) << endl;
}