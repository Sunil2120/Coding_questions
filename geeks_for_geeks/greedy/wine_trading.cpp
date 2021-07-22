#include<bits/stdc++.h>
using namespace std;


long long solve(vector<int>& arr,int n)
{
	queue<int> Q;
	long long work = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] < 0)
		{
			Q.push(i);
		}
	}
	for(int i=0;i<n;i++)
	{

		while(arr[i] > 0)//positive
		{
			int temp = min(abs(arr[i]),abs(arr[Q.front()]));
			arr[i]-=temp;
			work+=(abs(i-Q.front())*temp);
			arr[Q.front()]+=temp;
			if(arr[Q.front()]==0)
			{
				Q.pop();
			}

		}
	}
	return work;
}

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n==0)
		{
			break;
		}
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
	}
	
	return 0;
}