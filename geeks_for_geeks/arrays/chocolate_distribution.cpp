#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve(vector<int>& arr,int n,int m)
{
	sort(arr.begin(),arr.end());
	int min_value = INT_MAX;
	int i=0;
	while(i<n)
	{
		int next = i+(m-1);
		if(next >= n)
		{
			return min_value;
		}
		min_value = min(min_value,(arr[next]-arr[i]));
		i+=1;
	}
	return min_value;
}

int main()
{
	int n,m;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	cout << solve(arr,n,m) << endl;
}