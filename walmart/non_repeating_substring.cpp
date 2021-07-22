#include<bits/stdc++.h>
using namespace std;


int solve(string input,int k)
{
	int n = input.size();
	if(k > n)
	{
		return -1;
	}
	unordered_map<string,int> hash;
	
	for(int i=0;i<=n-k;i++)
	{
		string cur = input.substr(i,k);
		hash[cur]+=1;
	}
	for(int i=0;i<=n-k;i++)
	{
		string cur = input.substr(i,k);
		if(hash[cur]==1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	string input;
	cin >> input;
	int k;
	cin >> k;
	cout << solve(input,k) << endl;
	return 0;
}