#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solve(vector<int>& arr,int start,int end,int n)
{
	if(start > end)
	{
		return 0;
	}
	if(arr[start]==arr[end])
	{
		return solve(arr,start+1,end-1,n);
	}
	if(arr[start] < arr[end])
	{
		arr[start+1]=arr[start+1]+arr[start];
		return 1+solve(arr,start+1,end,n);
	}
	arr[high-1]+=arr[high];
	return 1 + solve(arr,start,end-1,n);

}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,0,n-1) << endl;
	return 0;
}