#include<bits/stdc++.h>
using namespace std;


void solve(int* arr,int n)
{
	int x_xor_y = 0;
	// xor of same numbers will result in zero
	// xor of zero and number is number itself(0^0=0   0^1 = 1)
	for(int i=0;i<n;i++)
	{
		x_xor_y = (x_xor_y^arr[i]);
	}
	//all numbers except unique number's xor is present
	//now we have separated them
	// if x_xor_y contains 1 means one number has O and another number has 1
	// so we will separated numbers with 0's and 1's and take xor of them
	int x=0;
	int y = 0;
	int rmsb = x_xor_y&(-x_xor_y);
	for(int i=0;i<n;i++)
	{
		if((arr[i]&rmsb)==0)
		{
			x = (x^arr[i]);
		}
		else
		{
			y = (y^arr[i]);
		}
	}
	cout << x << " " << y << endl;
	return ;

}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	solve(arr,n);
	return 0;
}