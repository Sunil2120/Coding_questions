#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	// first > second > third
	int first = INT_MIN;
	int second = INT_MIN;
	int third = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i] > first)
		{
			third = second;
			second = first;
			first = arr[i];
		}
		else if(arr[i] > second)
		{
			third = second;
			second = arr[i];
		}
		else if(arr[i] > third)
		{
			third = arr[i];
		}
	}
	cout << first << " " << second << " " << third << endl;
	return 0;


}