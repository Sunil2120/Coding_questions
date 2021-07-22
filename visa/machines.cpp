#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>>& arr,int index,int k,int n,int sum,int min_value)
{
	if(k > n)
	{
		return INT_MIN;
	}
	if(index>=n)
	{
		return INT_MIN;
	}
	if(k<=0)
	{
		cout << "called" << endl;
		return sum*min_value;
	}
	//include
	int temp1 = solve(arr,index+1,k-1,n,sum+arr[index].first,min(min_value,arr[index].second));
	int temp2 = solve(arr,index+1,k,n,sum,min_value);
	cout << temp1 << " " << temp2 << endl;
	return max(temp1,temp2);

}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++)
	{
		int f,s;
		cin >> f >> s;
		arr.push_back(make_pair(f,s));
	}
	cout << solve(arr,0,k,n,0,INT_MAX) << endl;
	return 0;
}