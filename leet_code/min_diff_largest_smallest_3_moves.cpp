// minimum difference b/w largest and smallest element in given arr int three moves

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
	sort(arr,arr+n);
	// first element as minimum
	// last three element is made as minimum element
	int opt1 = arr[n-4] - arr[0];
	// second element as minimum element
	// first element and last 2 elements are made as minimum_element
	int opt2 = arr[n-3] - arr[1];
	// third element as minimum element
	// first 2 elements and last 1 element are made as minimum_element
	int opt3 = arr[n-2] - arr[2];
	// fourth element as minimum element
	// first 3 elements are made as minimum_element
	int opt4 = arr[n-1] - arr[3];
	cout << min(opt1,min(opt2,min(opt3,opt4))) << endl;
}