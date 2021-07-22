#include<bits/stdc++.h>
using namespace std;



int solve_(int* arr,int n)
{
	vector<int> output(n,0);
	output[0]=1;
	for(int i=1;i<n;i++)
	{
		output[i]=1;
		int ans =output[i];
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j] > arr[i])
			{
				continue;
			}
			if(ans < output[j]+1)
			{
				ans = output[j]+1;
			}
		}
		output[i]=ans;
	}

	int best = 0;
	for(int i=0;i<n;i++)
	{
		if(output[i] > best)
		{
			best = output[i];
		}
	}
	return best;

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
	cout << solve_(arr,n) <<endl;
	delete []arr;
	return 0;
}