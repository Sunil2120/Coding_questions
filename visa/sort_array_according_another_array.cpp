#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	unordered_map<int,int> hash;
	vector<int> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
		hash[input[i]]+=1;
	}
	int m;
	cin >> m;
	vector<int> arr(m);
	vector<int> output;
	for(int i=0;i<m;i++)
	{
		cin >> arr[i];
		int value = hash[arr[i]];
		for(int j=0;j<value;j++)
		{
			output.push_back(arr[i]);
			hash[arr[i]]-=1;
		}
	}
	unordered_map<int,int> :: iterator it;
	for(it=hash.begin();it!=hash.end();it++)
	{
		if(it->second != 0)
		{
			output.push_back(it->first);
		}
	}
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return 0;
	
	return 0;

}