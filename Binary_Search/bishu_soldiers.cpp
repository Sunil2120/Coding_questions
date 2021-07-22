#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> sum(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		sum[i] = sum[i-1]+arr[i];
	}
	int q;
	cin >> q;
	while(q--)
	{
		int  power;
		cin >> power;
		int ans = -1;
		int low = 0;
		int high = n-1;
		while(low<=high)
		{
			int mid = (low+high)/2;
			if(arr[mid]==power)
			{
				ans = mid;
				break;
			}
			else if(power > arr[mid])
			{
				// it can be our ans
				ans = low;
				low = mid+1;
			}
			else
			{
				//left
				high = mid-1;
			}
		}
		cout << ans+1 << " " << sum[ans] << endl;
	}
	return 0;
}