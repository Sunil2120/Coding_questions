#include<bits/stdc++.h>
using namespace std;

// remember after sorting always traverse from the end
// codeforces contest 683 div 2 C by meet IT

//https://codeforces.com/contest/1447/problem/C

bool compare(pair<int,int>& a,pair<int,int>& b)
{
	return a.first < b.first;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		long long W;
		cin >> n >> W;
		vector<pair<int,int>> arr(n);
		for(int i=0;i<n;i++)
		{
			int val;
			cin >> val;
			arr[i]=make_pair(val,i+1);
		}
		sort(arr.begin(),arr.end(),compare);
		int ff=0;
		int index = -1;
		for(int i=0;i<n;i++)
		{
			if(arr[i].first<=W && arr[i].first>=ceil((W)/2.0))
			{
				ff=1;
				index = arr[i].second;
				break;
			}
		}
		if(ff)
		{
			cout << 1 << endl;
			cout << index << endl;
			continue;
		}
		ff=0;
		long long sum = 0;
		vector<int> output;
		for(int i=n-1;i>=0;i--)
		{
			if(sum+arr[i].first <= W)
			{
				sum+=arr[i].first;
				output.push_back(arr[i].second);
			}
			if(sum >= ceil((W)/2.0))
			{
				ff=1;
				break;
			}
		}
		if(ff==1)
		{
			sort(output.begin(),output.end());
			cout << output.size() << endl;
			for(int i=0;i<output.size();i++)
			{
				cout << output[i] << " ";
			}
			cout << endl;
			continue;
		}
		cout << -1 << endl;

	}
	
	return 0;

}