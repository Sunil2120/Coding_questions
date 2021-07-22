#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int last = arr[n-1];
        ll* sieve = new ll[last+1]();
        for(int i=0;i<n;i++)
        {
            sieve[arr[i]]+=1;
        }
        for(int i=last;i>=0;i--)
        {
            if(sieve[i]!=0)// that element is present in given set
            {
                for(int j=2;j*i<=last;j++)
                {
                    if(sieve[j*i]!=0)// that element is present in given set
                    {
                        sieve[i]+=sieve[j*i];
                        sieve[i]=sieve[i]%MOD;
                    }
                }
            }
        }
        ll total = 0;
        for(int i=0;i<n;i++)
        {
            total+=sieve[arr[i]];
            total=total%MOD;
        }
        cout << total << endl;

        delete[] arr;
        delete[] sieve;
    }
    
    return 0;
	


}