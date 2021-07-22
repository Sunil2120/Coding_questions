#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/given-n-appointments-find-conflicting-appointments/

// efficient method-2 using Interval Tree

// method-1 Time complexity O(n^2)
int solve(vector<pair<int,int>>& arr,int n)
{
	if(n==0)
	{
		return 0;
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			//check if intervals conflict
			if(arr[i].first > arr[j].first && arr[i].first < arr[j].second)
			{
				cout << "(" << arr[i].first << "," << arr[i].second << ")" << " " << "(" << arr[j].first << "," << arr[j].second << ")" << endl;
				count+=1;
				break;
			}
			
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++)
	{
		int f,s;
		cin >> f >> s;
		arr[i]=make_pair(f,s);
	}
	cout << solve(arr,n) << endl;
	return 0;
}