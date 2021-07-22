#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007


long long max(long long a,long long b)
{
    return a>b?a:b;
}

long long min(long long a,long long b)
{
    return a<b?a:b;
}

// if given array only contains negative and zero then max product subarray is 0
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int flag = 0;
	    int suni = 0;
	    int* arr = new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	    long long max_sofar = 1;
	    long long min_sofar = 1;
	    long long max_ = INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i] > 0)// positive
	        {
	            max_sofar = max_sofar*arr[i];
	            max_sofar = max_sofar%MOD;
	            min_sofar = min(1,min_sofar*arr[i]);
	            flag = 1;
	        }
	        else if(arr[i] < 0)
	        {
	            long long temp = max_sofar;
	            max_sofar = max(1,min_sofar*arr[i]);
	            max_sofar = max_sofar%MOD;
	            min_sofar = temp*arr[i];
	        }
	        else
	        {
	            max_sofar = 1;
	            min_sofar = 1;
	        }
	       
	        max_ = max(max_,max_sofar);
	    }
	    if(flag==0 && suni==1)// no positive elements
	    {
	    	cout << 0 << endl;
	    }
	    else
	    {
	    	cout << max_ << endl;
	    }
	    
	}
	return 0;
}