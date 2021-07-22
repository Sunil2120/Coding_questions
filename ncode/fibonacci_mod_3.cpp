#include<bits/stdc++.h>
using namespace std;


// pattern repeates after 8 fib number


int main()
{
	int t;
	cin >> t;
	int arr[8]={1,1,2,0,2,2,1,0};
	int sum = 0;
	for(int i=0;i<8;i++)
	{
		sum+=arr[i];
	}
	while(t--)
	{
		int n;
		cin >> n;
		int quotient = n/8;
		int remainder = n%8;
		int total = quotient*sum;
		for(int i=0;i<remainder;i++)
		{
			total+=arr[i];
		}
		cout << total << endl;
	}
	return 0;
}