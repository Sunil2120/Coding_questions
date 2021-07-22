#include<bits/stdc++.h>
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
		long long max_ending = 1;
		long long min_ending = 1;
		long long best = arr[0];
		if(n==1)
		{
			cout << arr[0] << endl;
			delete[] arr;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(arr[i] < 0)
			{
				// swap min and max
				long long temp = min_ending;
				min_ending = max_ending;
				max_ending = temp;
			}
			max_ending = max((max_ending*arr[i])%MOD,arr[i]);
			min_ending = min((min_ending*arr[i])%MOD,arr[i]);
			best = max(best%MOD,max_ending);
		}
		cout << best << endl;
		delete[] arr;
	}
}