#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    vector<int> output;
    while(t--)
    {
        int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    vector<long long> result ;
    // 0<= t <= 10^9
    for(int i=0;i<n;i++)
    {
        int start = 0;
        int end = 10^9;
        int ans = 0;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if((i+n*mid) >= arr[i])
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        result.push_back((i+ans*n));
    }
    long long min_x = INT_MAX;
    int min_i = -1;
    int s = result.size();
    for(int i=0;i<s;i++)
    {
        if(min_x > result[i])
        {
            min_x = result[i];
            min_i = i;
        }
    }
    output.push_back(min_i+1);
    delete[] arr;
    }
    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << endl;
    }
    
    return 0;
}