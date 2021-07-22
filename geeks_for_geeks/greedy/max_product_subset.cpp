#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int max_product = 1;
	// multiply positive elements
	// keep count of negative elements
	// get the least abs(negative value)
	int negative_count = 0;
	int min_element = INT_MAX;
	int check = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			check = 1;
			max_product*=arr[i];
		}
		if(arr[i] < 0)
		{
			negative_count+=1;
			min_element = min(min_element,abs(arr[i]));
		}
	}
	if(max_product < 0)//odd number of negatives 
	{
		max_product = max_product/min_element;
		max_product = max_product * -1;
	}
	if(check==0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << max_product << endl;
	return 0;
}