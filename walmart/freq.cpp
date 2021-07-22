#include<bits/stdc++.h>
using namespace std;

void solve(vector<long long>& arr,int n,int m,long long& max_value,int& output,int index,int cur,int cur_str)
{
   
    if(cur <= m)
    {
        if( cur> max_value)
        {
            max_value = cur;
            output = cur_str;
        }

    }
    if(index==n)
    {
        return ;
    }
    
    //include
    int temp = cur_str;
    cur_str = cur_str | (1<<index);
    solve(arr,n,m,max_value,output,index+1,cur+arr[index],cur_str);
    solve(arr,n,m,max_value,output,index+1,cur,temp);
    return ;
}

int main()
{
    freopen("first_input.txt","r",stdin);
    freopen("first_output.txt","w",stdout);
    
    int t;
    cin >> t;
    while(t--)
    {
        long long n,m;
        cin >> n >> m;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        long long max_value = INT_MIN;
        int output = 0;
       
        solve(arr,n,m,max_value,output,0,0,0);
        cout << max_value << endl;
        int cur = 1;
        for(int i=0;i<n;i++)
        {
            if((output&(1<<i)) != 0)
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}