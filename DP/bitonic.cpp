#include<bits/stdc++.h>
using namespace std;




int longestBitonicSubarray(int* arr,int n)
{
	cout << "hl" << endl;
	int* inc = new int[n]();
	int* dec = new int[n]();
	inc[0]=1;
	for(int i=1;i<n;i++)
	{
		inc[i]=1;
		int ans = inc[i];
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j] >= arr[i])
			{
				continue;
			}
			if(inc[j]+1 > ans)
			{
				ans = inc[j]+1;
			}
		}
		inc[i] = ans;
		//cout << ans << endl;
	}
	dec[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		dec[i]=1;
		int ans1 = dec[i];
		for(int j=i+1;j<n;j++)
		{
			if(arr[j] >= arr[i])
			{
				continue;
			}
			if(ans1 < dec[j]+1)
			{
				ans1=dec[j]+1;
			}
		}
		dec[i]=ans1;
	}

	for(int i=0;i<n;i++)
	{
		cout << inc[i] << " " << dec[i] << endl;
	}
	int best =0;

	for(int i=0;i<n;i++)
	{
		if((inc[i]+dec[i]) > best)
		{
			best = inc[i]+dec[i];
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	if(inc[i] > best)
	// 	{
	// 		best = inc[i];
	// 	}
	// }
	return best-1;
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
	return 0;
}