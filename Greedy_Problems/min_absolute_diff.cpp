#include<bits/stdc++.h>
using namespace std;


int min_absolute_diff(int n,int* input)
{
	if(n==0)
	{
		return 0;
	}

	sort(input,input+n);
	int min_x = 1000000000;
	for(int i=0;i<n-1;i++)
	{
		if(input[i+1]-input[i] < min_x)
		{
			min_x = input[i+1]-input[i];
		}
	}

	return min_x;
}

int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << min_absolute_diff(n,input) << endl;
	return 0;
}