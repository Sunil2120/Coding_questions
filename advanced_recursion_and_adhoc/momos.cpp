#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* t = new int[n];
	int to_sum=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		to_sum+=arr[i];
		t[i]=to_sum;	
	}
	int days=0;
	cin >> days;
	while(days--)
	{
		int price=0;
		cin >> price;
		int position = lower_bound(t,t+n,price) - t;
		if(position==0)
		{
			if(price < t[position])
			{
				cout << 0 << " " << price << endl;
			}
			else
			{
				cout << 1 << " " << price - t[position] << endl;
			}
			continue;
		}
		if(position==n)
		{
			cout << n << " " << price - t[n-1] << endl;
			continue;
		}
		if(t[position] > price)
		{

			cout << position-- << " " << price - t[position] << endl;
		}
		else
		{
			cout << position+1 << " " << price - t[position] << endl; 
		}
	}
	return 0;
}