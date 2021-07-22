#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> arr,int n,int value,int index,int sum)
{
	int count = 0;
	if(index >= arr.size())
	{
		return 0;
	}
	if(sum >= value)
	{
		return 0;
	}
	// if(sum >= value)
	// {
	// 	return 0;
	// }
	// exclude
	count+=solve(arr,n,value,index+1,sum);
	// include
	if(sum*arr[index] <  value)
	{
		count+=solve(arr,n,value,index+1,sum*arr[index])+1;
	}
	return count;
}

int main()
{
	int n,value;
	cin >> n >> value;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,value,0,1) << endl;
	return 0;
}