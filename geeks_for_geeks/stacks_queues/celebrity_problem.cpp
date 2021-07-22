#include<bits/stdc++.h>
using namespace std;


// Normal method using two for loops O(n^2)
// Finding celebrity in O(n)
// there can be either one celebrity or no celebrity
// there can't be multiple celebrities


// elemination method O(n)

// refer Pepcoding youtube channel
int solve(int** arr,int n)
{
	vector<int> s;
	for(int i=0;i<n;i++)
	{
		s.push_back(i);
	}
	while(s.size()>1)
	{
		int a = s.back();
		s.pop_back();
		int b = s.back();
		s.pop_back();
		if(arr[a][b]==1)// a knows b
		{
			// a can't be a celebrity
			s.push_back(b);
		}
		else if(arr[b][a]==1)// b knows a
		{
			// b can't be a celebrity
			s.push_back(a);
		}
		else if(arr[a][b]==0)// a doesnot know b
		{
			// a can be a celebrity
			s.push_back(a);
		}
		else if(arr[b][a]==0)// b doesnot know a
		{
			// b can be a celebrity
			s.push_back(b);
		}
	}
	int cur = s.back();
	s.pop_back();
	// checking row
	for(int i=0;i<n;i++)
	{
		if(arr[cur][i]!=0)
		{
			return -1;
		}
	}
	//checking col
	for(int i=0;i<n;i++)
	{
		if(i!=cur && arr[i][cur]!=1)
		{
			return -1;
		}
	}
	return cur;
}

int main()
{
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve(arr,n) << endl;
	return 0;
}