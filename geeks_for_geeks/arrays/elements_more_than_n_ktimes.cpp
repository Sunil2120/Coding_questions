#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;
	cin >> n >> k;
	unordered_map<int,int> hash;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		hash[arr[i]]+=1;
	}
	unordered_map<int,int> :: iterator it;
	int count = 0;
	int value = n/k;
	for(it=hash.begin();it!=hash.end();it++)
	{
		if(it->second >= value)
		{
			count+=1;
		}
	}
	cout << count << endl;
	return 0;

}