#include<bits/stdc++.h>
using namespace std;



bool check(vector<stack<int>>& arr1,vector<queue<int>>& arr2,int n,int e)
{
	for(int i=0;i<=n;i++)
	{
		stack<int> s = arr1[i];
		queue<int> q = arr2[i];
		while(!s.empty() && !q.empty())
		{
			if(s.top() != q.front())
			{
				return false;
			}
			s.pop();
			q.pop();
			if(s.size() != q.size())
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,e;
		cin >> n >> e;
		vector<stack<int>> arr1(n+1);
		vector<queue<int>> arr2(n+1);
		for(int i=0;i<e;i++)
		{
			int u,v;
			cin >> u >> v;
			arr1[u].push(v);
		}
		for(int i=0;i<e;i++)
		{
			int u,v;
			cin >> u >> v;
			arr2[u].push(v);
		}
		cout << check(arr1,arr2,n,e) << endl;
	}
}