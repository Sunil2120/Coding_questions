#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>& first,vector<int>& second,int n,int x,int y)
{
    if(n==0)
    {
        return 0;
    }
    int first_total = 0;
    int second_total = 0;
    int i=0;
    int j=0;
    int k=0;
    while(k<n && i<x && j<y)
    {
        if(first[k] > second[k])
        {
            first_total+=first[k];
            i+=1;
        }
        else
        {
            first_total+=second[k];
            j+=1;
        }
        k+=1;
        
    }
    while(i<x && k<n)
    {
        first_total+=first[k];
        k+=1;
        i+=1;
    }
    while(j<y && k<n)
    {
        first_total+=second[k];
        k+=1;
        j+=1;
    }
    k=n-1;
    i=0;
    j=0;
    while(k>=0 && i<x && j<y)
    {
        if(first[k] > second[k])
        {
            second_total+=first[k];
            i+=1;
        }
        else
        {
            second_total+=second[k];
            j+=1;
        }
        k-=1;
    }
    while(i<x && k>=0)
    {
        second_total+=first[k];
        k-=1;
        i+=1;
    }
    while(j<y && k>=0)
    {
        second_total+=second[k];
        k-=1;
        j+=1;
    }
    cout << first_total << " " << second_total << endl;
    return max(first_total,second_total);
}
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> first(n);
        vector<int> second(n);
        for(int i=0;i<n;i++)
        {
            cin >> first[i];
        }
        for(int i=0;i<n;i++)
        {
            cin >> second[i];
        }
        cout << solve(first,second,n,x,y) << endl;
    }
	return 0;
}