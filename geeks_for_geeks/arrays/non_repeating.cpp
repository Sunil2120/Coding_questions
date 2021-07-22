#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	unordered_map<int,int> hash;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		hash[arr[i]]+=1;
	}
	for(int i=0;i<n;i++)
	{
		if(hash[arr[i]] == 1)
		{
			cout << arr[i] << endl;
			break;
		}
	}
	return 0;
}