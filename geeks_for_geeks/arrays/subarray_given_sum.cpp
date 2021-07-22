#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		long long k;
		cin >> n >> k;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		unsigned int cur_sum = 0;
		int start = 0;
		int end = 0;
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			cur_sum+=arr[i];
			if(cur_sum >= k)
			{
				end = i;
				// we will start removing elements from the start, from cur_sum to know the exact 
				// subarray whose sum is k
				while(cur_sum > k && start < end)
				{
					cur_sum -= arr[start];
					start+=1;
				}
				if(cur_sum == k)
				{
					cout << start+1 << " " << end+1 << endl;
					flag = true;
					break;
				}
			}
		}
		if(flag == false)
		{
			cout << -1 << endl;
		}
		delete[] arr;
	}
	return 0;
}