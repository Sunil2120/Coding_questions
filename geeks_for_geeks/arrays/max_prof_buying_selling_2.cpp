// Maximum profit by buying and selling utmost twice transactions
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
	int* profit = new int[n];// max profit is stored
	int max_element = arr[n-1];
	profit[n-1]=0;
	// maximum profit with one transaction
	for(int i=n-2;i>=0;i--)
	{

		// maximum profit in subarray from i to n-1
		max_element = max(max_element,arr[i]);
		// maximum profit
		profit[i]=max(profit[i+1],max_element - arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout << profit[i] << " ";
	}
	cout << endl;
	// maximum profit with two transaction
	int min_element = arr[0];
	for(int i=1;i<=n-1;i++)
	{
		min_element = min(min_element,arr[i]);
		// maximum profit in subarray fromo 0 to i with 2 transaction
		profit[i]=max(profit[i-1],profit[i]+(arr[i]-min_element));
	}
	cout << profit[n-1] << endl;
	return 0;
}