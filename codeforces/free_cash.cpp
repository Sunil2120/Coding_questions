#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = INT_MIN;
	unordered_map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		int h,m;
		cin >> h >> m;
		int value = h*60 + m;
		hash[value]+=1;
		count = max(count,hash[value]);
	}
	cout << count << endl;
	return 0;
}