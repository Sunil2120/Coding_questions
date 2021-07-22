#include<bits/stdc++.h>
using namespace std;
// refer notes



int main()
{
	int t;
	cin >> t;
	int arr[8] = {0,1,1,2,0,2,2,1};
	
	int sum_arr[8] = {0,1,2,4,4,6,8,9};
	int sum = 9;
	while(t--)
	{
		int n;
		cin >> n;
		int total = 0;
		// total = previous groups sum + current fibonacci number
		// to get the previous groups n/8 period in case of mod3 is 8
		// after 8 fibonacci numbers starting from 0 the sequence repeats itself
		total += (n/8)*sum;
		// getting the current position int current groups
		int cur_pos = n%8;
		total += sum_arr[cur_pos];
		cout << total << endl;
	}
	return 0;
}