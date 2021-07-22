#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& input,int n,int k)
{
	if(n==0 || n==1)
	{
		return 0;
	}
	int left=0;
	int count = 0;
	int right = 0;
	sort(input.begin(),input.end());
	while(right < n && left <= right)
	{
		if(input[right]-input[left] == k)
		{
			count+=1;
			right+=1;
			left+=1;
			continue;
		}
		if(input[right]-input[left] < k)
		{
			right+=1;
		}
		else if(input[right]-input[left] > k)
		{
			left+=1;
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	int k;
	cin >> k;
	cout  << solve(input,n,k) << endl;
	return 0;
}