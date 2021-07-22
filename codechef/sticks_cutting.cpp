#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& sticks,int n)
{
	//sort(sticks.begin(),sticks.end());
	vector<int> temp;
	int* count = new int[n+1]()

	
	for(int i=0;i<n;i++)
	{
		count[sticks[i]]+=1;
	}
	int total = 0;
	for(int i=0;i<=n;i++)
	{
		if(count[i]>0)
		{
			total+=1;
		}
	}
	return total;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> sticks(n,0);
		for(int i=0;i<n;i++)
		{
			cin >> sticks[i];
		}
		cout << solve(sticks,n) << endl;
	}
	return 0;
}