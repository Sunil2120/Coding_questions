#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n,long long A,long long B,int index,long long cur)
{
	if(index==n)
	{
		if(cur>=A && cur<=B)
		{
			return 1;
		}
		return 0;
	}
	//include
	return solve(arr,n,A,B,index+1,cur+arr[index])+solve(arr,n,A,B,index+1,cur);
}

int main()
{
	int n;
	cin >> n;
	long long A,B;
	cin >> A >> B;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,A,B,0,0) << endl;
	return 0;
}