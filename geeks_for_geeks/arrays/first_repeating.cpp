#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000


int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> output;
		map<int,int> hash;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
			hash[arr[i]]=-1;
		}
		for(int i=0;i<n;i++)
		{
			if(hash[arr[i]]!=-1)
			{
				output.push_back(arr[i]);
			}
			else
			{
				hash[arr[i]]=i;
			}
		}
		int min_ = n;
		for(int i=0;i<output.size();i++)
		{
			int index = hash[output[i]];
			if(index < min_ )
			{
				min_ = index;
			}
		}
		if(min_ == n)
		{
			cout << -1 << endl;

		}
		else
		{
			cout << min_+1 << endl;
		}
		
		delete[] arr;

	}
	
	return 0;
}