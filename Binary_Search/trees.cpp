#include<bits/stdc++.h>
using namespace std;

// we should find the maximum height 


bool is_valid(vector<int>& trees,int n,int value,int mid)
{
	int temp = 0;
	for(int i=0;i<n;i++)
	{
		if(trees[i] > mid)
		{
			temp+=(trees[i]-mid);
		}
		if(temp>=value)
		{
			return true;
		}
	}
	return false;
}
int solve(vector<int>& trees,int n,int value)
{
	sort(trees.begin(),trees.end());
	int low = 0;
	int high = trees[n-1];
	int ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(is_valid(trees,n,value,mid)==true)
		{
			ans = mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return ans;
}
int main()
{
	int n,value;
	cin >> n >> value;
	vector<int> trees(n);
	for(int i=0;i<n;i++)
	{
		cin >> trees[i];
	}
	cout << solve(trees,n,value) << endl;
	return 0;
}