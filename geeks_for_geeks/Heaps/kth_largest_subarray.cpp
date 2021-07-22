#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int n,int k)
{
	//kth largest - min heap
	priority_queue<int,vector<int>,greater<int>> Q;
	for(int i=0;i<n;i++)
	{
		int  sum = 0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			Q.push(sum);
			if(Q.size() > k)
			{
				Q.pop();
			}
		}
	}
	return Q.top();
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
	int k;
	cin >> k;
	cout << solve(arr,n,k) << endl;
	return 0;
}