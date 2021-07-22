#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int* arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int max =0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]> max)
			{
				max = arr[j];
			}
		}
		a.push_back(abs(max-arr[i]));
		max=0;
	}
	cout << *max_element(a.begin(),a.end());
	return 0;
}