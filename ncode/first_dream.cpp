#include<bits/stdc++.h>
using namespace std;


int solve(int** arr,int n)
{
    int count = 0;
    for(int j=0;j<n;j++)
    {
        int i=0;
        while(i<10)
        {
            if(arr[j][i]==0)
            {
                int temp = 0;
                while(i<10 && arr[j][i]==0)
                {
                    i++;
                    temp+=1;
                    if(temp==4)
                    {
                        break;
                    }
                }
                if(temp==4)
                {
                    count+=1;
                }
            }
            else if(arr[j][i]==1)
            {
                int temp = 0;
                if(i-1>=0 && arr[j][i-1]==0)
                {
                    temp+=1;
                }
                if(i-2>=0 && arr[j][i-2]==0)
                {
                    temp+=1;
                }
                if(i+1<10 && arr[j][i+1]==0)
                {
                    temp+=1;
                }
                if(i+2<10 && arr[j][i+2]==0)
                {
                    temp+=1;
                }
                if(temp==4)
                {
                    count+=1;
                    i=i+3;
                }
                else
                {
                    i+=1;
                }
            }
            else
            {
                i+=1;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    vector<int> output;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int** arr = new int*[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=new int[10];
            for(int j=0;j<10;j++)
            {
                arr[i][j]=0;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin >> a >> b;
            a = a-1;
            b=b-1;
            arr[a][b]=2;
        }
        for(int i=0;i<n;i++)
        {
            arr[i][3]=1;
            arr[i][7]=1;
        }
        
        output.push_back(solve(arr,n));
        delete[] arr;
        
    }
    while(output.size()>0)
    {
        cout << output.back() << " ";
        output.pop_back();
    }
    return 0;
}